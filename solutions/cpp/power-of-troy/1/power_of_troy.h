#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

class human {
    public:
        std::unique_ptr<artifact> possession {nullptr};
        std::shared_ptr<power> own_power {nullptr};
        std::shared_ptr<power> influenced_by {nullptr};
};

void give_new_artifact(human& receiver, std::string effect);
void exchange_artifacts(std::unique_ptr<artifact>& art1, std::unique_ptr<artifact>& art2);
void manifest_power(human& receiver, std::string new_power);
void use_power(human& caster, human& target);
int power_intensity(const human& wielder);
    
}  // namespace troy
