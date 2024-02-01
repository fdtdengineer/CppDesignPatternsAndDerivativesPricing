#include <cmath>
#include <iostream>
#include "Random1.hpp"


double SimpleMonteCarlo1(
    double Expiry,
    double Strike,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
) {
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot * exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i=0; i<NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }
    
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}


int main() {
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    double Vol=0.25;
    double r=0;
    unsigned long NumberOfPaths=100;
    double result = SimpleMonteCarlo1(
        Expiry,
        Strike,
        Spot,
        Vol,
        r,
        NumberOfPaths
        );
 
    std::cout <<"the price is " << result << std::endl;
    return 0;
}
