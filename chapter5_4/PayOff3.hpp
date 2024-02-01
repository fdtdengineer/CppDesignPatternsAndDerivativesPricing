#ifndef PAYOFF3_HPP
#define PAYOFF3_HPP

#include <algorithm>


class PayOff
{
private:
public:
    PayOff(){};
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){};
    virtual PayOff* clone() const=0;
};


class PayOffCall : public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){};
    virtual PayOff* clone() const;
private:
    double Strike;
};


class PayOffPut : public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){};
    virtual PayOff* clone() const;
private:
    double Strike;
};



#endif