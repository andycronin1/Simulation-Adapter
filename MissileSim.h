#pragma once
#include <iostream>
#include "SimulationInterface.h"

class MissileSimulation : public Simulation {
    public: 
        virtual void simMethod(int &data) override {
            std::cout << "Missile Sim Running Method" << std::endl;
        }
};