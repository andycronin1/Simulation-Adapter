#pragma once
#include <iostream>

class DummyApiClient {
    public:
        int makeRequest(const std::string& data) {
            // In a real API client, you'd make an HTTP request here
            // and handle the response, errors, etc.
            std::cout << "API client received request: " << data << std::endl;        
            // Always return 1 for this dummy implementation
            return 1; 
        }
    };