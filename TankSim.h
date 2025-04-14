#pragma once 
#include <iostream>
#include "SimulationInterface.h"

class TankSimulation : public Simulation {
    public: 
        virtual void simMethod(int &data) override {
            std::cout << "Tank Sim Running Method" << std::endl;
        }
};