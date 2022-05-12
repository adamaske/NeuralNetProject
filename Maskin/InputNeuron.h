#pragma once
#include "Neuron.h"
#include <cmath>
class InputNeuron :
    public Neuron
{
public:
    InputNeuron();
    float mPower = 1;
    virtual float Output() override;
};

