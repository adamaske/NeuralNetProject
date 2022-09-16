#include "Neuron.h"
#include <cmath>
#include "NeuronLink.h"
#include "Entity.h"

void Neuron::GetToMeLink(NeuronLink* link)
{
	mToMe.push_back(link);
}
void Neuron::GetFromMeLink(NeuronLink* link)
{
	mFromMe.push_back(link);
}
float Neuron::Output()
{

	return 0.0f;
}
