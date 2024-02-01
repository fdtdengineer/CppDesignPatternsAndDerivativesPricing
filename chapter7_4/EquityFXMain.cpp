#include <cmath>
#include <iostream>
#include "ParkMiller.hpp"
#include "MCStatistics.hpp"
#include "ConvergenceTable.hpp"
#include "AntiThetic.hpp"
#include "PathDependentAsian.hpp"
#include "ExoticBSEngine.hpp"

int main() {
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    double Vol=0.25;
    double r=0.1;
    unsigned long NumberOfPaths=10000;
    unsigned long NumberOfDates=100;

    PayOffCall thePayOff(Strike);
    MJArray times(NumberOfDates);
    
    for (unsigned long i=0; i<NumberOfDates; i++){
        times[i] = (i + 1.0) * Expiry / NumberOfDates;
    }

    ParametersConstant rParam(r);
    ParametersConstant dParam(r);
    ParametersConstant VolParam(Vol);
    PathDependentAsian theOption(times, Expiry, thePayOff);
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    RandomParkMiller generator(NumberOfDates);
    AntiThetic GenTwo(generator);
    ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine.DoSimulation(gathererTwo, NumberOfPaths);
    std::vector<std::vector<double>> results = gathererTwo.GetResultSoFar();

    for (unsigned long i=0; i<results.size(); i++) {
        for (unsigned long j=0; j<results[i].size(); i++) {
            std::cout << results[i][j] << " ";
        }
        std::cout << "\n";
    }    


    return 0;
}
