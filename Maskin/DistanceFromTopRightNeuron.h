#pragma once
#include "InputNeuron.h"

class DistanceFromTopRightNeuron :
    public InputNeuron
{
public:
    DistanceFromTopRightNeuron(Entity* entity);   

    virtual float Output() override;
};

