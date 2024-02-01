#include "MCStatistics.hpp"


StatisticsMean::StatisticsMean() : RunningSum(0.), PathsDone(0){}

void StatisticsMean::DumpOneResult(double result) {
    PathsDone++;
    RunningSum += result;
}


std::vector<std::vector<double>> StatisticsMean::GetResultSoFar() const {
    std::vector<std::vector<double>> Result(1);
    Result[0].resize(1);
    Result[0][0] = RunningSum / PathsDone;
    return Result; 
}

StatisticsMC* StatisticsMean::clone() const {
    return new StatisticsMean(*this);
}


