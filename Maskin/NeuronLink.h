#pragma once
class Neuron;
class NeuronLink
{
public:
	NeuronLink(Neuron* a, Neuron* b, float weight);

	Neuron* mTo;
	Neuron* mFrom;

	float mWeight = 0;
	float Output();
};

