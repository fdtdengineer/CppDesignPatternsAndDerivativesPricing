#ifndef TREE_EUROPEAN_H
#define TREE_EUROPEAN_H

#include "TreeProduct.hpp"
#include "PayOffBridge.hpp"
#include <algorithm>


class TreeEuropean : public TreeProduct
{
private:
    PayOffBridge ThePayOff;
public:
    TreeEuropean(double FinalTime, const PayOffBridge& ThePayOff_);
    virtual TreeProduct* clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
    virtual ~TreeEuropean(){};
};


#endif