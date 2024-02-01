#include <cmath>
#include <iostream>
#include "SimpleMC3.hpp"
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
    
    PayOffCall CallPayOff(Strike);
    VanillaOption theOptionCall(CallPayOff, Expiry);

    PayOffPut PutPayOff(Strike);
    VanillaOption theOptionPut(PutPayOff, Expiry);

    PayoffDoubleDigital DDPayOff(LowerLevel, UpperLevel);
    VanillaOption theOptionDD(DDPayOff, Expiry);


    double resultCall = SimpleMonteCarlo3(
        theOptionCall,
        Spot,
        Vol,
        r,
        NumberOfPaths
        );
 
     double resultPut = SimpleMonteCarlo3(
        theOptionPut,
        Spot,
        Vol,
        r,
        NumberOfPaths
        );

     double resultDD = SimpleMonteCarlo3(
        theOptionDD,
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
