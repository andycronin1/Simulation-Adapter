
#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include "app.h"
#include "MissileSim.h"
// #include "TankSim.h"

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


class Adapter : public App { 
    public:
        // CONSTRUCTOR

        // Adapter takes a pointer to an intstance of the simulation interface
        Adapter(Simulation* o, DummyApiClient* c) : obj{ o }, client{c} {}

        // get the data from the API 
        int data = client->makeRequest("12");

        // When we call the app method, we are actually calling the simulation
        virtual void appMethod(int& data) override { obj->simMethod(data); }
    
    private:

        Simulation* obj = nullptr;
        DummyApiClient* client = nullptr;

    };

// // Factory class for creating Adapter instances
// class StatefulWidgetFactory {
//     public:
//         static std::unique_ptr<Adapter> createAdapter(const std::string& simulationType) {
//             auto client = std::make_unique<DummyApiClient>();

//             if (simulationType == "Missile") {
//                 return std::make_unique<Adapter>(new MissileSimulation(), client);
//             } else if (simulationType == "Tank") {
//                 return std::make_unique<Adapter>(new TankSimulation(), client);
//             } else {
//                 // Handle invalid simulation type
//                 return nullptr;
//             }
//         }
//     };

int main() {


    // Create adapters for different simulation types
    auto client = std::make_unique<DummyApiClient>();
    auto missileAdapter = std::make_unique<Adapter>(new MissileSimulation(), client.get());
    // std::unique_ptr<Adapter> tankAdapter = StatefulWidgetFactory::createAdapter("Tank");

    int data1 = 0; // Initialize data variables
    missileAdapter->appMethod(data1); 
    // tankAdapter->appMethod(data2); 
      
    return 0;
  }



