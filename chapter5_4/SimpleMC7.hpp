#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include "MCStatistics.hpp"

void SimpleMonteCarlo5(
    const VanillaOption& TheOption,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths,
    StatisticsMC& gatherer
);

#endif