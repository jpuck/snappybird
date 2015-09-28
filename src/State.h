/*
  The contents of this file are dedicated by all of its authors, including

    Michael S. Gashler, Jeff Puckett

  to the public domain (http://creativecommons.org/publicdomain/zero/1.0/).
*/

#include "string.h"
#include "Model.h"
#include "json/json.h"
#include <fstream>
#include <iostream>

#ifndef STATE_H
#define STATE_H

class State
{
public:
	Model& m_model;
	double discretizer;
	vector<std::string> stateVars;
	vector< std::pair<std::string,double> > stateSettings;

public:
	State(Model& m);
	virtual ~State();
	std::string toCSV();
};

#endif // STATE_H
