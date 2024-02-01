#include <cmath>
#include <iostream>
#include "SimpleMC8.hpp"
#include "ParkMiller.hpp"
#include "Vanilla3.hpp"
#include "MCStatistics.hpp"
#include "ConvergenceTable.hpp"
#include "AntiThetic.hpp"

int main() {
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    double Vol=0.25;
    double r=0.1;
    unsigned long NumberOfPaths=10000;
    
    PayOffCall CallPayOff(Strike);
    VanillaOption theOptionCall(CallPayOff, Expiry);
    ParametersConstant rParam(r);
    ParametersConstant VolParam(Vol);
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);

    SimpleMonteCarlo6(
        theOptionCall,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths,
        gathererTwo,
        GenTwo
        );
 
    std::vector<std::vector<double>> results = gathererTwo.GetResultSoFar();

    std::cout << "\nFor the call price the results are \n";

    for (unsigned long i=0; i<results.size();i++){
        for (unsigned long j=0; j<results[i].size();i++){
            std::cout << results[i][j] << " ";
        }
        std::cout << "\n";
    }


    return 0;
}
