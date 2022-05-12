#include "Genome.h"
#include "NeuronLink.h"
#include "Neuron.h"
Genome::Genome()
{
	
}
Genome::Genome(std::vector<NeuronLink*> links)
{
	mLinks = links;
}
void Genome::CreateRandomLinks(std::vector<Neuron*> neurons)
{
	//Go trough all neurons
	for (size_t i = 0; i < neurons.size(); i++)
	{
		//Check that this is not an output neuron
		if (neurons[i]->mType != NeuronType::Output) {
			//Should i create a link from this
			if (rand() % 20 > 18) { // 10% chance ? 
				//Create nuron link
				NeuronLink* neuronLink;
				//From node
				Neuron* first = neurons[i];
				//To node
				Neuron* last = neurons[rand() % neurons.size() - 1];
				//Inits link
				neuronLink = new NeuronLink(first, last, 1);
				mLinks.push_back(neuronLink);
			}
		}
		
	}
}

void Genome::MutateGenome()
{
	//Pick random neuron
}

