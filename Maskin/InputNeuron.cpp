#include "InputNeuron.h"

InputNeuron::InputNeuron()
{
	mType = NeuronType::Input;
}

InputNeuron::InputNeuron(Entity* entity)
{
	mEntity = entity;
}

float InputNeuron::Output()
{
	//Calculate some info here
	return 0;
}
