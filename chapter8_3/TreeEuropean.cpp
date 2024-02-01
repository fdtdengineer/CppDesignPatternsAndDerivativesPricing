#include "TreeEuropean.hpp"

TreeEuropean::TreeEuropean(double FinalTime, const PayOffBridge& ThePayOff_) : TreeProduct(FinalTime), ThePayOff(ThePayOff_) {}

TreeProduct* TreeEuropean::clone() const
{
    return new TreeEuropean(*this);
}

double TreeEuropean::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double, double, double DiscountedFutureValue) const
{
    // Different from American
    return DiscountedFutureValue;
}


