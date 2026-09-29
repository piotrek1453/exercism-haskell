// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
static constexpr unsigned ovenTime() {
    return 40;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven. */
unsigned remainingOvenTime(const unsigned& actualMinutesInOven) {
    return ovenTime() - actualMinutesInOven;
}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer. */
unsigned preparationTime(const unsigned& numberOfLayers) {
    static constexpr unsigned int minutesPerLayer{2};
    return minutesPerLayer * numberOfLayers;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
unsigned int elapsedTime(const unsigned& numberOfLayers, const unsigned& actualMinutesInOven) {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}
