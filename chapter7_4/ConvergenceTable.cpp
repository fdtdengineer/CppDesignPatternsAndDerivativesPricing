#include "ConvergenceTable.hpp"

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_) : Inner(Inner_) {
    StoppingPoint = 2;
    PathsDone = 0;
}


StatisticsMC* ConvergenceTable::clone() const {
    return new ConvergenceTable(*this);
}


void ConvergenceTable::DumpOneResult(double result) {
    Inner->DumpOneResult(result);
    ++PathsDone;

    if (PathsDone == StoppingPoint) {
        StoppingPoint*=2;
        std::vector<std::vector<double>> thisResult(Inner->GetResultSoFar());

        for (unsigned long i=0; i<thisResult.size(); i++) {
            thisResult[i].push_back(PathsDone);
            ResultsSoFar.push_back(thisResult[i]);
        }
    }
}


std::vector<std::vector<double>> ConvergenceTable::GetResultSoFar() const {
    std::vector<std::vector<double>> arr(ResultsSoFar);

    if (PathsDone*2 != StoppingPoint) {
        std::vector<std::vector<double>> thisResult(Inner->GetResultSoFar());

        for (unsigned long i=0; i<thisResult.size();i++){
            thisResult[i].push_back(PathsDone);
            arr.push_back(thisResult[i]);
        }
    }
    return arr;
}






