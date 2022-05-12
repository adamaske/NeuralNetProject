#include "OutputNeuron.h"
#include "NeuronLink.h"
OutputNeuron::OutputNeuron()
{
	mType = NeuronType::Output;
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
