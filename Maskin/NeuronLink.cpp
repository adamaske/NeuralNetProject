#include "NeuronLink.h"
#include "Neuron.h"
NeuronLink::NeuronLink(Neuron* a, Neuron* b, float weight)
{
	mFrom = a;
	mTo = b;
	mWeight = weight;

	//Adds this link to the last neuron in the link
	mFrom->GetFromMeLink(this);
	mTo->GetToMeLink(this);
	
}

float NeuronLink::Output()
{
	
	return 0.0f;
}
