#include "Payoff1.hpp"
#include <algorithm>

PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
:
    Strike(Strike_), TheOptionsType(TheOptionsType_)
{}

double PayOff::operator ()(double spot) const
{
    switch (TheOptionsType)
    {
    case call:
        return std::max(spot - Strike, 0.);

    case put:
        return std::max(Strike - spot, 0.);

    default:
        throw("unknown option type found.");
    }
}
