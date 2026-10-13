#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human& receiver, std::string effect) {
    receiver.possession = std::make_unique<artifact>(effect);
}

void exchange_artifacts(std::unique_ptr<artifact>& art1, std::unique_ptr<artifact>& art2) {
    std::swap(art1, art2);
}

void manifest_power(human& receiver, std::string new_power) {
    receiver.own_power = std::make_shared<power>(new_power);
}

void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(const human& wielder) {
    return wielder.own_power.use_count();
}
    
}  // namespace troy
