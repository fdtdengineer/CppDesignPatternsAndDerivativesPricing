#include <cmath>
#include <iostream>
#include "BinomialTree.hpp"
#include "TreeAmerican.hpp"
#include "TreeEuropean.hpp"
//#include "BlackScholesFormula.hpp"
#include "PayOffForward.hpp"

int main() {
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    double Vol=0.25;
    double r=0.1;
    unsigned long Steps=100;

    PayOffPut thePayOff(Strike);
    ParametersConstant rParam(r);
    ParametersConstant dParam(r);
    TreeAmerican europeanOption(Expiry, thePayOff);
    TreeEuropean americanOption(Expiry, thePayOff);    
    SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, Steps, Expiry);

    double europeanPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    
    std::cout << "The European-Call Price" << europeanPrice << std::endl;
    std::cout << "The American-Call Price" << americanPrice << std::endl;

    return 0;
}
