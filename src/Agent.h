/*
  The contents of this file are dedicated by all of its authors, including

    Michael S. Gashler, Jeff Puckett

  to the public domain (http://creativecommons.org/publicdomain/zero/1.0/).
*/

#include <iostream>
#include "Model.h"
#include "rand.h"
#include "State.h"
#include "qTable.h"

#ifndef AGENT_H
#define AGENT_H

class Agent
{
public:
	double explorationRate;
	double learningRate;
	double discountFactor;

	Rand randNum;
	Model& m_model;
	State state;
	std::string previousState;
	bool died;
	bool flapped;
	qTable qt;
	
	bool playing;

public:
	Agent(Model& m);
	virtual ~Agent();
	bool update();
	double calculateQ();
};

#endif // AGENT_H