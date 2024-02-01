#include "TreeProduct.hpp"

TreeProduct::TreeProduct(double FinalTime_) : FinalTime(FinalTime_)
{
}

double TreeProduct::GetFinalTime() const
{
    return FinalTime;
}
