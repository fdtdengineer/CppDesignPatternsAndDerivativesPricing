#include "Random1.hpp"


double GetOneGaussianBySummation(){
    unsigned long jmax = 12;
    double result = 0;

    for (unsigned long j=0; j<jmax; j++){
        result += rand() / static_cast<double>(RAND_MAX);
    }
    result -= jmax / 2;
    return result;
}


double GetOneGaussianByBoxMuller() {
    double result;
    double x, y;
    double sizeSquared;
    do {
        x = 2.0*rand() / static_cast<double>(RAND_MAX)-1;
        y = 2.0*rand() / static_cast<double>(RAND_MAX)-1;
        sizeSquared = x * x + y * y;
    }
    while
    (sizeSquared >= 1.0);
    result = x*sqrt(-2*log(sizeSquared)/sizeSquared);
    return result;
}


/*
int main(){
    std::cout << "hello" << std::endl;
    return 0;
}
*/

/*


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
*/