
#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include "dummyTankAPI.h"
#include "dummySoldierApi.h"
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

    // Create simulations
    std::unique_ptr<DummyApiClient> tankSim = std::make_unique<DummyTankApiClient>();
    std::unique_ptr<DummyApiClient> soldierSim = std::make_unique<DummySoldierApiClient>();
    // Create adapters
    auto tankAdapter = std::make_unique<Adapter>(tankSim.get());
    auto soldierAdapter = std::make_unique<Adapter>(soldierSim.get());

    int data1 = 1;
    int data2 = 2;

    // Run simulations
    tankAdapter->appMethod(data1);
    soldierAdapter->appMethod(data2);

    // std::cout << "Tank Sim Data Returned: " << data1 << std::endl;
    // std::cout << "Solider Sim Data Return: " << data2 << std::endl;

    return 0;
}



