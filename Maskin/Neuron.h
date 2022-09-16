#pragma once
#include <vector>
enum NeuronType{Input, Internal, Output};
class Entity;
class NeuronLink; 
class Neuron
{
public:
	//What type is this
	NeuronType mType = Input;

	std::vector<NeuronLink*> mToMe;
	std::vector<NeuronLink*> mFromMe;
	void GetToMeLink(NeuronLink* link);
	void GetFromMeLink(NeuronLink* link);
	virtual float Output();

	Entity* mEntity;
};

