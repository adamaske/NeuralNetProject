#pragma once
#include "Neuron.h"
#include <cmath>
class InputNeuron :
    public Neuron
{
public:
    InputNeuron();
    InputNeuron(Entity* entity);
    float mPower = 1;
    virtual float Output() override;
};

