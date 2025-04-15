#pragma once
#include <iostream>

// API interface
class DummyApiClient {
    public:
        virtual int makeRequest(const int &data) = 0;

        // `Destructor must be virtual as we are often defining pointers of type DummyApiClient (base class) that point to derived classes
        virtual ~DummyApiClient() {std::cout << "Base API Destructor \n"; }
    };
