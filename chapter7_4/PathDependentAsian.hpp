#ifndef PATH_DEPENDENT_ASIAN_H
#define PATH_DEPENDENT_ASIAN_H
#include "PathDependent.hpp"
#include "PayOffBridge.hpp"


class PathDependentAsian : public PathDependent
{
private:
    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned long NumberOfTimes;
    
public:
    PathDependentAsian(
        const MJArray& LookAtTimes_,
        double DeliveryTime_,
        const PayOffBridge& ThePayOff_
        );
    virtual unsigned long MaxNumberOfCashFlows() const;
    virtual MJArray PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PathDependentAsian(){}
    virtual PathDependent* clone() const;
};



#endif