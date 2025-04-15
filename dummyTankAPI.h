#pragma once
#include <iostream>
#include "SimulationInterface.h"

class DummyTankApiClient : public DummyApiClient {
    public:
        virtual int makeRequest(const int& data) override {
            // In a real API client, you'd make an HTTP request here
            // and handle the response, errors, etc.
            std::cout << "Tank API client received request: " << data << std::endl;        
            // Always return 1 for this dummy implementation
            return 1; 
        }
    };