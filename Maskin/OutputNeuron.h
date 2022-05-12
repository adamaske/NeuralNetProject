#pragma once
#include "Neuron.h"
class Action;
class OutputNeuron :
    public Neuron
{
public:
    OutputNeuron(Action* action);
    //How likely this is to fire
    virtual float Output() override;
    Action* mAction;
};

