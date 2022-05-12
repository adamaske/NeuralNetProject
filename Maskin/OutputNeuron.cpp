#include "OutputNeuron.h"
#include "NeuronLink.h"
#include "Action.h"
OutputNeuron::OutputNeuron(Action* action)
{
	mType = NeuronType::Output;
	mAction = action;
}

float OutputNeuron::Output()
{
	float weight = 0;
	for (size_t i = 0; i < mLinks.size(); i++)
	{
		//If the output of the first neuron on the link is 0, dont add any probablility to fire
		weight += mLinks[i]->mWeight * mLinks[i]->mFirst->Output();
	}
	//Wants sum of all the input links
	return tanh(weight);
}
