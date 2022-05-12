#include "NeuralNet.h"
#include "OutputNeuron.h"
#include "InputNeuron.h"
#include "InternalNeuron.h"
#include "Action.h"
NeuralNet::NeuralNet()
{
	//Create my neurons
	// Input neurons 
	
	// Internal neruons
	
	//Action neurons
	mActionNeurons.push_back(new OutputNeuron(new MoveForward()));
	mActionNeurons.push_back(new OutputNeuron(new MoveBackwards()));
	mActionNeurons.push_back(new OutputNeuron(new MoveRight()));
	mActionNeurons.push_back(new OutputNeuron(new MoveLeft()));

	//Adds all 
	for (size_t i = 0; i < mInputNeurons.size(); i++)
	{
		mAllNeurons.push_back(dynamic_cast<Neuron*>(mInputNeurons[i]));
	}

	for (size_t i = 0; i < mInternalNeurons.size(); i++)
	{
		mAllNeurons.push_back(dynamic_cast<Neuron*>(mInternalNeurons[i]));
	}

	for (size_t i = 0; i < mActionNeurons.size(); i++)
	{
		mAllNeurons.push_back(dynamic_cast<Neuron*>(mActionNeurons[i]));
	}
}
