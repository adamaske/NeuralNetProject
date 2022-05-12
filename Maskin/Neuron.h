#pragma once
#include <vector>
enum NeuronType{Input, Internal, Output};
class NeuronLink; 
class Neuron
{
public:
	//What type is this
	NeuronType mType = Input;
	std::vector<NeuronLink*> mLinks;
	void GetLink(NeuronLink* link);
	virtual float Output();
};

