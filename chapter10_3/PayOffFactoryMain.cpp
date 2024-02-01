#include "PayOff3.hpp"
#include "PayOffConstructible.hpp"
#include "PayOffBridge.hpp"
#include "PayOffFactory.hpp"

#include <string>
#include <iostream>


int main(){
    double Strike=1;
    double r=0.1;
    double d=0;
    std::string name = "call";
    
    PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);
    
    if (PayOffPtr!=NULL)
    {
        double Spot=1.4;
        //double Vol=0.25;
        //double Expiry=1;
        double dblPayOff = PayOffPtr->operator()(Spot);
        delete PayOffPtr;
    }

    std::cout << "done" << std::endl;;


}