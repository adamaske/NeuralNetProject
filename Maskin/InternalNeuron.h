#pragma once
#include "Neuron.h"
class InternalNeuron :
    public Neuron
{
public:
    InternalNeuron();
    virtual float Output() override;
};

