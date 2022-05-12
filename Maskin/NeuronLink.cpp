#include "NeuronLink.h"

NeuronLink::NeuronLink(Neuron* a, Neuron* b, float weight)
{
	mFirst = a;
	mLast = b;
	mWeight = weight;
}
