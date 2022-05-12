#include "Entity.h"
#include "NeuralNet.h"
#include "Genome.h"
Entity::Entity(int x, int y)
{
	mX = x;
	mY = y;
	mGenome = new Genome();
	mBrain = new NeuralNet();

}

Entity::Entity(int x, int y, Genome* genome, NeuralNet* nuralnet)
{
	mX = x;
	mY = y;

	mGenome = genome;
	mBrain = nuralnet;
}

Entity* Entity::Reproduce()
{
	Entity* entity = new Entity(mX, mY, mGenome, mBrain);

	return nullptr;
}
