#include "NeuronLink.h"
#include "Neuron.h"
NeuronLink::NeuronLink(Neuron* a, Neuron* b, float weight)
{
	mFirst = a;
	mLast = b;
	mWeight = weight;

	//Adds this link to the last neuron in the link
	mLast->GetLink(this);

}
