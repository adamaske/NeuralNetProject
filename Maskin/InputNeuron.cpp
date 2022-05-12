#include "InputNeuron.h"

InputNeuron::InputNeuron()
{
	mType = NeuronType::Input;
}

float InputNeuron::Output()
{
	return mPower;
}
