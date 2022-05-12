#pragma once
class Genome;
class NeuralNet;
class Entity
{
public:
	Entity(int x, int y);
	Entity(int x, int y, Genome* genome, NeuralNet* nuralnet);
	int mX = 0;
	int mY = 0;

	Genome* mGenome;
	NeuralNet* mBrain;
	
	Entity* Reproduce();
};

