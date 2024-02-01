#ifndef PAYOFF_HPP
#define PAYOFF_HPP

class PayOff
{
    public:
        enum OptionType {call, put};
        PayOff(double Strike_, OptionType TheOptionsType_);
        double operator()(double spot) const;

    private:
        double Strike;
        OptionType TheOptionsType;
};

#endif