#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP

#include "Vanilla3.hpp"

double SimpleMonteCarlo3(
    const VanillaOption& TheOption,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
);

#endif