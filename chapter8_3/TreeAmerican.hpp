#ifndef TREE_AMERICAN_H
#define TREE_AMERICAN_H

#include "TreeProduct.hpp"
#include "PayOffBridge.hpp"
#include <algorithm>


class TreeAmerican : public TreeProduct
{
private:
    PayOffBridge ThePayOff;
public:
    TreeAmerican(double FinalTime, const PayOffBridge& ThePayOff_);
    virtual TreeProduct* clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
    virtual ~TreeAmerican(){};
};


#endif