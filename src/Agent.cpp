/*
  The contents of this file are dedicated by all of its authors, including

    Michael S. Gashler, Jeff Puckett

  to the public domain (http://creativecommons.org/publicdomain/zero/1.0/).
*/

#include "Agent.h"

Agent::Agent()
: randNum(0), explorationRate(0.01), learningRate(1.0), discountFactor(0.99)
{
}

Agent::~Agent()
{
}

