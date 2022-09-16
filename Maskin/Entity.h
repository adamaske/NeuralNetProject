#pragma once
#include <vector>
#include <iostream>
#include <iostream>
class Genome;
class NeuralNet;
class Entity
{
public:
	Entity(int x, int y, float geneAmount, float internalSize, std::string name);
	Entity(int x, int y, std::vector<Genome*> genes, NeuralNet* nuralnet, int _r, int _g, int _b);
	int mX = 0;
	int mY = 0;
	int r;
	int g;
	int b;

	std::vector<Genome*> mGenes;
	NeuralNet* mBrain;
	
	Entity* Reproduce();
	bool Reproduced();
	std::string mName;

	void Update();
};

