#pragma once

// Simulation interface
class DummyApiClient {
    public:
        virtual int makeRequest(const int &data) = 0;
    };