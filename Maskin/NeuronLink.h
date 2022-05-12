#pragma once
class Neuron;
class NeuronLink
{
public:
	NeuronLink(Neuron* a, Neuron* b, float weight);

	Neuron* mFirst;
	Neuron* mLast;

	float mWeight = 0;
};

