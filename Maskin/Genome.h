#pragma once
#include <vector>
class NeuronLink;
class Neuron;
class Genome
{
public:
	Genome();
	Genome(std::vector<NeuronLink*> links);
	

	std::vector<NeuronLink*> mLinks;

	void CreateRandomLinks(std::vector<Neuron*> neurons);
	void MutateGenome();
};

