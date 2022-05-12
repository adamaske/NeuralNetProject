#pragma once
#include "Neuron.h"
class OutputNeuron :
    public Neuron
{
public:
    OutputNeuron();
    //How likely this is to fire
    virtual float Output() override;
};

