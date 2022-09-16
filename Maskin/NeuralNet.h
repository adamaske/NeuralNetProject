#pragma once
#include <vector>
class Neuron;
class InputNeuron;
class InternalNeuron;
class OutputNeuron;
class Entity;
class NeuralNet
{
public:
	NeuralNet(Entity* entity);
	std::vector<Neuron*> mAllNeurons;
	std::vector<InputNeuron*> mInputNeurons;
	std::vector<InternalNeuron*> mInternalNeurons;
	std::vector<OutputNeuron*> mOutputNeurons;

	Entity* mEntity;
};

