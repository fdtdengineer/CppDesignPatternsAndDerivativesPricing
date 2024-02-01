#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP
#include "Payoff2.hpp"
#include "Vanilla1.hpp"

double SimpleMonteCarlo3(
    const VanillaOption& TheOption,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
);

#endif