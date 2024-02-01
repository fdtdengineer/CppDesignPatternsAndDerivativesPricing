#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

#include "TreeProduct.hpp"
#include <vector>
#include "Parameters.hpp"
#include "Arrays.hpp"

class SimpleBinomialTree
{
private:
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;
    std::vector<std::vector<std::pair<double, double>>> TheTree;
    MJArray Discounts;
protected:
    void BuildTree();
public:
    SimpleBinomialTree(
        double Spot_,
        const Parameters& r_,
        const Parameters& d_,
        double Volatility_,
        unsigned long Steps_,
        double Time_
    );
    double GetThePrice(const TreeProduct& TheProduct);
};




#endif