#ifndef Vanilla1_HPP
#define Vanilla1_HPP

#include "PayOff2.hpp"

class VanillaOption
{
public:
    VanillaOption(PayOff& ThePayOff_, double Expiry_);
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;

private:
    double Expiry;
    PayOff& ThePayOff;
};


#endif