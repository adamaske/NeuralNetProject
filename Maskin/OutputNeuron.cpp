#include "OutputNeuron.h"
#include "NeuronLink.h"
#include "Action.h"
#include <iostream>
OutputNeuron::OutputNeuron(Action* action)
{
	mType = NeuronType::Output;
	mAction = action;
}

float OutputNeuron::Output()
{
	std::cout << "Output nueron began Output function" << std::endl;
	float weight = 0;
	for (size_t i = 0; i < mToMe.size(); i++)
	{
		//If the output of the first neuron on the link is 0, dont add any probablility to fire
		weight += mToMe[i]->mWeight * mToMe[i]->mFrom->Output();
	}
	//Wants sum of all the input links
	return tanh(weight);
}
