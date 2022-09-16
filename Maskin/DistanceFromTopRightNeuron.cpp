#include "DistanceFromTopRightNeuron.h"
#include "Entity.h"
#include <iostream>
DistanceFromTopRightNeuron::DistanceFromTopRightNeuron(Entity* entity)
{
    mEntity = entity;
}

float DistanceFromTopRightNeuron::Output()
{
    std::cout << "Distance from top right is asked for its strength!" << std::endl;
    std::cout << "My entity is " << mEntity->mName << std::endl;
    std::cout << "I have " << mFromMe.size() << " links from me!" << std::endl;
    for (int i = 0; i < mFromMe.size(); i++) {

    }
    if (mEntity) {
        std::cout << "DistanceFromTopRight began Output function" << std::endl;
        float xPos = mEntity->mX;
        float yPos = mEntity->mY;

        //Refrence to map size
        //Fake it while it lasts
        float maxX = 800;
        float maxY = 600;


        float newX = maxX - xPos;
        float newY = maxY - yPos;

        float distance = sqrt(pow(newX, 2)+pow(newY, 2));
        float maxDistance = sqrt(pow(maxX, 2) + pow(maxY, 2));

        std::cout << "DistanceFromTopRight: " << distance/maxDistance << std::endl;
        return distance / maxDistance;
    }
    return 0.0f;
}
