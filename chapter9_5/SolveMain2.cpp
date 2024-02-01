#include "NewtonRaphson.hpp"
#include <cmath>
#include <iostream>
#include "BSCallTwo.hpp"
#include "BlackScholesFormulas.hpp"


int main(){
    double Expiry=1;
    double Strike=1;
    double Spot=1;
    //double Vol=0.25;
    double r=0.1;
    double d=0;

    double Price=0.14975798173511773;
    double Start=1;
    

    double tolerance=1e-10;
    BSCallTwo theCall(r, d, Expiry, Spot, Strike);
    //double Price_tmp = theCall(Vol);
    //std::cout << Price_tmp << std::endl;;

    double ImpVol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price, Start, tolerance, theCall);

    std::cout << ImpVol << std::endl;;


}