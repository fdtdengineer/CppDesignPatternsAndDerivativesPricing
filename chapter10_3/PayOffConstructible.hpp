#ifndef PAYOFF_CONSTRUCTIBLE_HPP
#define PAYOFF_CONSTRUCTIBLE_HPP

#if defined(_MSC_VER)
#pragma warning(disable : 4786)
#endif

#include <iostream>
#include "PayOff3.hpp"
#include "PayOffFactory.hpp"
#include <string>

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(std::string);
    static PayOff* Create(double);
};


template <class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
    return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}


#endif