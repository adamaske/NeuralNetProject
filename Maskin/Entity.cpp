#include "Entity.h"
#include "NeuralNet.h"
#include "Genome.h"
#include "OutputNeuron.h"
#include "Action.h"
#include <iostream>
Entity::Entity(int x, int y, float geneAmount, float internalSize, std::string name)
{
	mName = name;
	mX = x;
	mY = y;
	//Creates nerual net, which creates all the neurons
	mBrain = new NeuralNet(this);
	//Creates genomes, ingore for now
	for (size_t i = 0; i < geneAmount; i++)
	{
		mGenes.push_back(new Genome(mBrain));
	}

	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;

	

}

Entity::Entity(int x, int y, std::vector<Genome*> genes, NeuralNet* nuralnet, int _r, int _g, int _b)
{
	mX = x;
	mY = y;

	mGenes = genes;
	mBrain = nuralnet;

	r = _r;
	g = _g;
	b = _b;
}

Entity* Entity::Reproduce()
{
	Entity* entity = new Entity(mX, mY, mGenes, mBrain, r, g, b);

	return nullptr;
}

bool Entity::Reproduced()
{
	//Bare repoduser om man er innerst i kordinatene
	if (mX > 50 && mX < 550 && mY > 50 && mY < 750) {
		return true;
	}
	else {
		return false;
	}
}

void Entity::Update()
{
	//
	std::cout << "Entity began update function" << std::endl;
	int indexToBeDone = 0;
	float highestOutput = 0;
	//Get action nuerons that should be done
	for (size_t i = 0; i < mBrain->mOutputNeurons.size(); i++)
	{
		std::cout << "Started calculating OutputNeurons " << i << " on " << mName << std::endl;
		//Find the highest output
		float output = mBrain->mOutputNeurons[i]->Output();
		if (output > highestOutput) {
			highestOutput = output;
			indexToBeDone = i;
		}
		std::cout << "Finished calculating OutputNueron " << i << " on " << mName << std::endl;
	}
	//Do the action
	mBrain->mOutputNeurons[indexToBeDone]->mAction->DoAction(this);
}
