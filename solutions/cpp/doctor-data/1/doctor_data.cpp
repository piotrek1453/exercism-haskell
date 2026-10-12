#include "doctor_data.h"

namespace heaven {
    std::string get_older_bob(const Vessel& vessel1, const Vessel& vessel2) {
        if (vessel1.generation < vessel2.generation) {
            return vessel1.name;
        } else {
            return vessel2.name;
        }
    }

    bool in_the_same_system(const Vessel& vessel1, const Vessel& vessel2) {
        return vessel1.current_system == vessel2.current_system;
    }
    
    Vessel::Vessel(std::string name, int generation, star_map::System system) :
    name(name),
    generation(generation),
    current_system(system)
    {}

    Vessel Vessel::replicate(std::string new_name) {
        return Vessel(new_name, generation + 1, current_system);
    }

    void Vessel::make_buster() {
        busters++;
    }

    bool Vessel::shoot_buster() {
        if (busters > 0) {
            busters--;
            return true;
        } else {
            return false;
        }
    }
}