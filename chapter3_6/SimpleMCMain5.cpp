#include <cmath>
#include <iostream>
#include "SimpleMC2.hpp"
#include "DoubleDigital.hpp"

int main() {
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    double Vol=0.25;
    double r=0.1;
    unsigned long NumberOfPaths=10000;

    double LowerLevel = 0.5;
    double UpperLevel = 2.;
    

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);
    PayoffDoubleDigital DDPayOff(LowerLevel, UpperLevel);
    

    double resultCall = SimpleMonteCarlo2(
        callPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
        );
 
     double resultPut = SimpleMonteCarlo2(
        putPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
        );

     double resultDD = SimpleMonteCarlo2(
        DDPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
        );

    std::cout <<"the call price is " << resultCall << std::endl;
    std::cout <<"the put price is "  << resultPut  << std::endl;
    std::cout <<"the DoubleDigital price is "  << resultDD  << std::endl;
    

    return 0;
}
