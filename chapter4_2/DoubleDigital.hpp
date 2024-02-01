#ifndef DoubleDigital_HPP
#define DoubleDigital_HPP

#include "PayOff2.hpp"

class PayoffDoubleDigital : public PayOff
{
private:
    double LowerLevel;
    double UpperLevel;
public:
    PayoffDoubleDigital(double LowerLevel_, double UpperLevel_);
    ~ PayoffDoubleDigital(){};
    virtual double operator() (double Spot) const;
};

#endif