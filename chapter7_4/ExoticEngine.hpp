#ifndef EXOTIC_ENGINE_H
#define EXOTIC_ENGINE_H
#include "Wrapper.hpp"
#include "Parameters.hpp"
#include "PathDependent.hpp"
#include "MCStatistics.hpp"
#include <vector>

class ExoticEngine
{
private:
    Wrapper<PathDependent> TheProduct;
    Parameters r;
    MJArray Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
public:
    ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);
    virtual void GenOnePath(MJArray& SpotValues)=0;
    void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
    virtual ~ExoticEngine(){}
    double DoOnePath(const MJArray& SpotValues) const;
};




#endif