#include "InternalNeuron.h"
#include "NeuronLink.h"
#include <cmath>
InternalNeuron::InternalNeuron()
{
	mType = NeuronType::Internal;
}

float InternalNeuron::Output()
{
	float weight = 0;
	for (size_t i = 0; i < mLinks.size(); i++)
	{
		//If the first neuron has an output of 0, then adds zero to the p
		weight += mLinks[i]->mWeight * mLinks[i]->mFirst->Output();
	}
	//Wants sum of all the input links
	return tanh(weight);
}
