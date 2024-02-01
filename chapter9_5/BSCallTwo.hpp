#ifndef BS_CALL_TWO_HPP
#define BS_CALL_TWO_HPP

class BSCallTwo
{
private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;
    
public:
    BSCallTwo(double r_, double d_, double T_, double Spot_, double Strike_);
    double Price(double Vol) const;
    double Vega(double Vol) const;    
    //double operator()(double Vol) const;
};

#endif