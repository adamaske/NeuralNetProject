#pragma once
#include <vector>
class Neuron;
class InputNeuron;
class InternalNeuron;
class OutputNeuron;
class NeuralNet
{
public:
	NeuralNet();
	std::vector<Neuron*> mAllNeurons;
	std::vector<InputNeuron*> mInputNeurons;
	std::vector<InternalNeuron*> mInternalNeurons;
	std::vector<OutputNeuron*> mActionNeurons;
};

