#ifndef PAY_OFF_FORWARD_HPP
#define PAY_OFF_FORWARD_HPP

#include <algorithm>
#include "PayOff3.hpp"

class PayOffForward : public PayOff
{
public:
    PayOffForward(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffForward(){};
    virtual PayOff* clone() const;
private:
    double Strike;
};




#endif