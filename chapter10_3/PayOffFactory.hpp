#ifndef PAYOFF_FACTORY_HPP
#define PAYOFF_FACTORY_HPP
#include "PayOff3.hpp"
// #include <algorithm>

#include <map>
#include <string>

class PayOffFactory
{
public:
    typedef PayOff* (*CreatePayOffFunction)(double);
    static PayOffFactory& Instance();
    void RegisterPayOff(std::string PayOffId, CreatePayOffFunction CreatorFunction);
    PayOff* CreatePayOff(std::string PayOffId, double Strike);
    ~PayOffFactory(){};    

private:
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator= (const PayOffFactory&){ return *this; }
};


#endif