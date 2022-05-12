#pragma once
#include <vector>
class NeuronLink;
class Neuron;
class NeuralNet;
class Genome
{
public:
	Genome(NeuralNet* brain);
	Genome(std::vector<NeuronLink*> links);
	

	std::vector<NeuronLink*> mLinks;

	void CreateRandomLinks(std::vector<Neuron*> neurons);
	void MutateGenome();
};

