
#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include "dummyTankAPI.h"
#include "app.h"

class Adapter : public App { 
    public:
        // CONSTRUCTOR

        // Adapter takes a pointer to an instance of the dummyAPI
        Adapter(DummyApiClient* c) : client{c} {}

        // Override the app method with the clients make request method 
        virtual void appMethod(int& data) override { client->makeRequest(data); }

        // // When we call the local app method, we are actually calling the simulation
        // virtual void appMethod(int& data) override { obj->simMethod(data); }

    
    private:

        // Initialise pointers
        DummyApiClient* client = nullptr;

    };

int main() {


    // Create dummy api client
    auto client = std::make_unique<DummyTankApiClient>();
    // Create missile sim adapter. Takes in a missile simulation and gets the address of the client 
    auto missileAdapter = std::make_unique<Adapter>(client.get());

    // Initialize data variables
    int data1 = 0;

    // Run app method on the missile adapter 
    missileAdapter->appMethod(data1); 
      
    return 0;
  }



