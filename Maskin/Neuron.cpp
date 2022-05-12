#include "Neuron.h"
#include <cmath>
#include "NeuronLink.h"
void Neuron::GetLink(NeuronLink* link)
{
	mLinks.push_back(link);
}
float Neuron::Output()
{

	return 0.0f;
}
