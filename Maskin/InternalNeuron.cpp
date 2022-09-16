#include "InternalNeuron.h"
#include "NeuronLink.h"
#include <cmath>
InternalNeuron::InternalNeuron()
{
	mType = NeuronType::Internal;

}

float InternalNeuron::Output()
{
	float weight = (rand() % 100)/100;
	for (size_t i = 0; i < mToMe.size(); i++)
	{
		//If the first neuron has an output of 0, then adds zero to the p
		weight += mToMe[i]->mWeight * mToMe[i]->mFrom->Output();
	}
	//Wants sum of all the input links
	return tanh(weight);
}
