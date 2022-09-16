// Maskin.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Global.h"
#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include "Entity.h"
#include <string>
#include <chrono>
#include <thread>
#define HEIGHT 800
#define WIDTH 600
void QuitApp(SDL_Window* window, SDL_Renderer* renderer);
void Draw(SDL_Renderer* renderer, std::vector<Entity*> entities);
void Wait(std::chrono::milliseconds amount);
int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        //No init
        return 1;
    };
    //Pointer til viduet
    SDL_Window* mWindow = nullptr;
    SDL_Renderer* mRenderTarget = nullptr;
    //Lager window
    mWindow = SDL_CreateWindow("Machine Learning", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
    mRenderTarget = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mWindow == NULL) {
        //Get fucked
        QuitApp(mWindow, mRenderTarget);
        return 0;
    }
    
    
    SDL_Event ev;

    //Generations
    int mGenerations = 5;
    int mStepsInGeneration = 10;
    float geneAmount = 5;
    float internalSize = 1;
    //Create entites
    std::vector<Entity*> entities;
    int entityAmount = 10;
    for (size_t i = 0; i < 10; i++)
    {
        //
        Entity* e = new Entity(rand() % HEIGHT, rand() % WIDTH, geneAmount, internalSize, "Entity " + std::to_string(i));
        entities.push_back(e);
    }
    bool isRunning = true;
    while (isRunning) {
        //Henter event som skjer
        while (SDL_PollEvent(&ev) != 0) {
            //Hvis det er av type KEYDOWn
            if (ev.type == SDL_KEYDOWN) {
                //Switch som går på symbolet som ble trykker
                switch (ev.key.keysym.sym) {
                    //Hvis det er escape
                case SDLK_ESCAPE:
                    QuitApp(mWindow, mRenderTarget);

                    break;
                case SDLK_RIGHT:
                    //Next step?
                    break;
                }               
            }
        }

        for (int i = 0; i < mGenerations; i++) {
            //Is this the first generation? Dont generate new entites if its the first generation         
            if (i != 0) {
                std::vector<Entity*> newEntites;
                //Do reproduction every generation
                //Check every entity for reproduction
                for (size_t i = 0; i < entities.size(); i++)
                {
                    //If they reproduced
                    if (entities[i]->Reproduced()) {
                        //newEntites.push_back(new Entity(rand() % HEIGHT, rand() % WIDTH, 0, 0, "Entity " + std::to_string(i)));
                        newEntites.push_back(new Entity(entities[i]->mX, entities[i]->mY, 0, 0, "Entity " + std::to_string(i)));
                    }
                }

                //Refill enities with missing amount
                entities = newEntites;
                int remainingEntites = entityAmount - entities.size();
                for (int j = 0; j < remainingEntites; j++) {
                    entities.push_back(new Entity(rand() % HEIGHT, rand() % WIDTH, geneAmount, internalSize, "Entity " + std::to_string(i)));
                }
            }
            
            for (int j = 0; j < mStepsInGeneration; j++) {
                for (size_t k = 0; k < entities.size(); k++)
                {
                    std::cout << "Started update of entity" << std::endl;
                    entities[k]->Update();
                }
                //Calls draw function
                Draw(mRenderTarget, entities);
                std::cout << "Finished step "<< j << " in Generation " << i << std::endl;
                Wait(std::chrono::milliseconds(300));
            }
            std::cout << "Finished generation " << i << std::endl;
        }
        //Exit simulation
        isRunning = false;
        Draw(mRenderTarget, entities);
    }

    QuitApp(mWindow, mRenderTarget);
    return 0;
}

void QuitApp(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    exit(1);
}

void Draw(SDL_Renderer* renderer, std::vector<Entity*> entities)
{
    // We clear what we draw before
    SDL_RenderClear(renderer);
    // Set our color for the draw functions
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // Now we can draw our point
    for (size_t i = 0; i < entities.size(); i++)
    {
        //Set color to entites color
        SDL_SetRenderDrawColor(renderer, entities[i]->r, entities[i]->g, entities[i]->b, 0xFF);
        //Draw point with color at entity posistion
        SDL_RenderDrawPoint(renderer, entities[i]->mX, entities[i]->mY);
        SDL_RenderDrawPoint(renderer, entities[i]->mX+1, entities[i]->mY);
        SDL_RenderDrawPoint(renderer, entities[i]->mX-1, entities[i]->mY);
        SDL_RenderDrawPoint(renderer, entities[i]->mX+1, entities[i]->mY-1);
        SDL_RenderDrawPoint(renderer, entities[i]->mX-1, entities[i]->mY+1);
        SDL_RenderDrawPoint(renderer, entities[i]->mX+1, entities[i]->mY+1);
        SDL_RenderDrawPoint(renderer, entities[i]->mX-1, entities[i]->mY-1);
        SDL_RenderDrawPoint(renderer, entities[i]->mX, entities[i]->mY+1);
        SDL_RenderDrawPoint(renderer, entities[i]->mX, entities[i]->mY-1);
    }

    // Set the color to what was before
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    // .. you could do some other drawing here
    // And now we present everything we draw after the clear.
    SDL_RenderPresent(renderer);
}

void Wait(std::chrono::milliseconds amount)
{
    std::this_thread::sleep_until(std::chrono::system_clock::now() + amount);
}
