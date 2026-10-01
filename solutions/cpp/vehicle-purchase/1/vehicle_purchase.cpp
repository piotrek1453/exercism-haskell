#include "vehicle_purchase.h"
#include <array>
#include <algorithm>
#include <string_view>

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(const std::string kind) {
    static constexpr std::array<std::string_view, 2> requireLicense {"car", "truck"};
    
    return std::find(requireLicense.begin(), requireLicense.end(), kind) != requireLicense.end();
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    return std::min(option1, option2) + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    if(age < 3.0) {
        return 0.8 * original_price;
    } else if (age >= 10.0) {
        return 0.5 * original_price;
    } else {
        return 0.7 * original_price;
    }
}

}  // namespace vehicle_purchase
