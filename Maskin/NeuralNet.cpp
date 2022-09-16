#include "NeuralNet.h"
#include "OutputNeuron.h"
#include "InputNeuron.h"
#include "InternalNeuron.h"
#include "NeuronLink.h"
#include "Action.h"
#include "DistanceFromTopRightNeuron.h"
#include "Entity.h"
#include <iostream>
#include <string>
NeuralNet::NeuralNet(Entity* entity)
{
	mEntity = entity;
	//Create my neurons
	// Input neurons 
	std::cout << "NeuralNet: A new NuralNet is created, coming from " + mEntity->mName << std::endl;
	mInputNeurons.push_back(new DistanceFromTopRightNeuron(entity));
	std::cout << "NeuralNet: Created InputNueron" << std::endl;
	// Internal neruons
	for (size_t i = 0; i < 2; i++) {
		mInternalNeurons.push_back(new InternalNeuron());
		std::cout << "NeuralNet: Created InternalNeuron " + std::to_string(i) << std::endl;
	}
	//Action neurons
	mOutputNeurons.push_back(new OutputNeuron(new MoveForward()));
	mOutputNeurons.push_back(new OutputNeuron(new MoveBackwards()));
	mOutputNeurons.push_back(new OutputNeuron(new MoveRight()));
	mOutputNeurons.push_back(new OutputNeuron(new MoveLeft()));
	std::cout << "NeuralNet: Created OutputNeurons" << std::endl;
	//Adds all 
	for (size_t i = 0; i < mInputNeurons.size(); i++)
	{
		std::cout << "NeuralNet: InputNeuron number " + std::to_string(i) + " was added to mAllNeurons!" << std::endl;
		mAllNeurons.push_back(dynamic_cast<Neuron*>(mInputNeurons[i]));

		//Connect all the input neurons to every internal neuron
		for (size_t j = 0; j < mInternalNeurons.size(); j++) {

			NeuronLink* link = new NeuronLink(mInputNeurons[i], mInternalNeurons[j], (rand() % 100)/100);
			
			std::cout << "NeuralNet: Created a link between InputNeuron " + std::to_string(i) + " and InternalNeuron " + std::to_string(j) << std::endl;
		}
	}

	for (size_t i = 0; i < mInternalNeurons.size(); i++)
	{
		mAllNeurons.push_back(dynamic_cast<Neuron*>(mInternalNeurons[i]));
		std::cout << "NeuralNet: InternalNeuron number " + std::to_string(i) + " was added to mAllNeurons!" << std::endl;
		//Connect all the internal to every action neuron
		for (size_t j = 0; j < mOutputNeurons.size(); j++)
		{
			NeuronLink* link = new NeuronLink(mInternalNeurons[i], mOutputNeurons[j], (rand() % 100) / 100);
			std::cout << "NeuralNet: Created a link between InternalNeuron " + std::to_string(i) + " and OutputNeuron " + std::to_string(j) << std::endl;
		}
	}

	for (size_t i = 0; i < mOutputNeurons.size(); i++)
	{
		std::cout << "NeuralNet: OutputNeuron number " + std::to_string(i) + " was added to mAllNeurons!" << std::endl;
		mAllNeurons.push_back(dynamic_cast<Neuron*>(mOutputNeurons[i]));
	}

	std::cout << "NeuralNet: Completed setting up brain for " + mEntity->mName << std::endl;
}
