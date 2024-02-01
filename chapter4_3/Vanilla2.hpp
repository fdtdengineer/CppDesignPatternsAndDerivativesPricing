#ifndef Vanilla1_HPP
#define Vanilla1_HPP

#include "PayOff3.hpp"

class VanillaOption
{
public:
    VanillaOption(PayOff& ThePayOff_, double Expiry_);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption& original);
    ~VanillaOption();

    double GetExpiry() const;
    double OptionPayOff(double Spot) const;

private:
    double Expiry;
    PayOff* ThePayOffPtr;
};


#endif