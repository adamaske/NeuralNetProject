#include "Entity.h"
#include "NeuralNet.h"
#include "Genome.h"
#include "OutputNeuron.h"
#include "Action.h"
Entity::Entity(int x, int y, float geneAmount, float internalSize)
{
	mX = x;
	mY = y;
	//Creates nerual net, which creates all the neurons
	mBrain = new NeuralNet();
	//Creates genomes
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

void Entity::Update()
{
	//
	std::vector<OutputNeuron*> mToBeDone;

	//Get action nuerons that should be done
	for (size_t i = 0; i < mBrain->mActionNeurons.size(); i++)
	{
		if (mBrain->mActionNeurons[i]->Output() > 0.5f) {
			mToBeDone.push_back(mBrain->mActionNeurons[i]);
		}
	}
	//Do the actoins
	for (size_t i = 0; i < mToBeDone.size(); i++)
	{
		mToBeDone[i]->mAction->DoAction(this);
	}
}
