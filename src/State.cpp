/*
  The contents of this file are dedicated by all of its authors, including

    Michael S. Gashler, Jeff Puckett

  to the public domain (http://creativecommons.org/publicdomain/zero/1.0/).
*/

#include "State.h"

State::State(Model& model)
: m_model(model), discretizer(1.0)
{
	stateVars.push_back("Bird.Velocity-Y");
	stateVars.push_back("Bird-NextTube.Delta-Y");
	stateVars.push_back("Bird-NextTube.Delta-X");
	stateVars.push_back("NextTube.Up");
	
	stateSettings.push_back(std::pair<std::string,double>("Discretizer", discretizer));
}

State::~State()
{
	Json::Value StateSettingsJSON;
	Json::StyledWriter styledWriter;
	for (size_t i=0; i<stateVars.size(); i++)
		StateSettingsJSON["Variables"].append(stateVars[i]);

	for (size_t i=0; i<stateSettings.size(); i++)
		StateSettingsJSON[stateSettings[i].first] = stateSettings[i].second;
	
	//array["StateSettings"]["InstanceID"].append(uuid);
	/*for (size_t i=0; i<sizeof uuid; i++) {
		array["StateSettings"]["InstanceID"].append(uuid);
		printf("%02x ", uuid[i]);
	}*/
	
	Json::Value test;
	test["InstanceID"] = 1;
	test["StateSettings"] = StateSettingsJSON;

	std::cout << styledWriter.write(test);
}

std::string State::toCSV()
{
	std::string s = "";
	// find next tube
	if(m_model.tubes.size() > 0){
	  int i = 0;
	  while(m_model.tubes[i]->x < m_model.bird.x){
		i++;
	  }
	  // next tube up/down
	  s += to_str(m_model.tubes[i]->up);
	  // difference between bird-y and tube-y
	  s += "," + to_str((m_model.bird.y - m_model.tubes[i]->y) / discretizer);
	  // difference between bird-x and tube-x
	  s += "," + to_str((m_model.tubes[i]->x - m_model.bird.x) / discretizer);
	}
	else s += "1," + to_str((m_model.bird.y - 500) / discretizer) + "," + to_str(400 / discretizer);

	// bird-y velocity
	s += "," + to_str(m_model.bird.vert_vel / discretizer);
	return s;
}
