#ifndef ConvergenceTable_HPP
#define ConvergenceTable_HPP

#include "MCStatistics.hpp"
#include "Wrapper.hpp"

class ConvergenceTable : public StatisticsMC
{
private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultSoFar() const;
};


#endif