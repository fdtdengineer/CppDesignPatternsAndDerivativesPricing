#ifndef PAYOFF2_HPP
#define PAYOFF2_HPP

#include <algorithm>


class PayOff
{
private:
public:
    PayOff(){};
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){};
};


class PayOffCall : public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){};
private:
    double Strike;
};


class PayOffPut : public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){};
private:
    double Strike;
};



#endif