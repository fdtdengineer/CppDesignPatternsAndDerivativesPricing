#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP
#include "Payoff2.hpp"

double SimpleMonteCarlo2(
    const PayOff& thePayOff,
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
);

#endif