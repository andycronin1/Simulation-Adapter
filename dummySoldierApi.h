#pragma once
#include <iostream>
#include "DummyApiInterface.h"

class DummySoldierApiClient : public DummyApiClient {
    public:
        virtual int makeRequest(const int& data) override {
            // In a real API client, you'd make an HTTP request here
            // and handle the response, errors, etc.
            std::cout << "Solider API client received request: " << data << std::endl;        
            // Always return 1 for this dummy implementation
            return 1; 
        }

        ~DummySoldierApiClient() {std::cout << "Soldier API Destructor \n";  }

    };