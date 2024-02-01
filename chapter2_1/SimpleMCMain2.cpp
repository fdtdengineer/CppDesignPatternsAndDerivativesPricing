#include <cmath>
#include <iostream>
#include "SimpleMC.hpp"

int main() {
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    double Vol=0.25;
    double r=0.1;
    unsigned long NumberOfPaths=10000;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);
    
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

    std::cout <<"the call price is " << resultCall << std::endl;
    std::cout <<"the put price is "  << resultPut  << std::endl;

    return 0;
}
