#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(const double& hourly_rate) {
    return 8.0 * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(const double& before_discount, const double& discount) {
    return before_discount - (before_discount * (discount / 100.0));
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(const double& hourly_rate, const double& discount) {
    constexpr unsigned billableDaysPerMonth{22};
    return std::ceil(billableDaysPerMonth * apply_discount(daily_rate(hourly_rate), discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(const int& budget, const double& hourly_rate, const double& discount) {
    return budget / apply_discount(daily_rate(hourly_rate), discount);
}
