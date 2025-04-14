
#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include "app.h"
#include "MissileSim.h"
#include "TankSim.h"


class Adapter : public App { 
    public:
        // CONSTRUCTOR

        // Adapter takes a pointer to an intstance of the simulation interface
        Adapter(Simulation* o) : obj{ o } {}

        // When we call the app method, we are actually calling the simulation
        virtual void appMethod() override { obj->simMethod(); }
    
    private:

        Simulation* obj = nullptr;

    };

// Factory class for creating Adapter instances
class StatefulWidgetFactory {
    public:
        static std::unique_ptr<Adapter> createAdapter(const std::string& simulationType) {
            if (simulationType == "Missile") {
                return std::make_unique<Adapter>(new MissileSimulation());
            } else if (simulationType == "Tank") {
                return std::make_unique<Adapter>(new TankSimulation());
            } else {
                // Handle invalid simulation type
                return nullptr;
            }
        }
    };

int main() {
    // Create adapters for different simulation types
    std::unique_ptr<Adapter> missileAdapter = StatefulWidgetFactory::createAdapter("Missile");
    std::unique_ptr<Adapter> tankAdapter = StatefulWidgetFactory::createAdapter("Tank");

    // Use the adapters to run the simulations
    missileAdapter->appMethod();
    tankAdapter->appMethod();

    return 0;
}

