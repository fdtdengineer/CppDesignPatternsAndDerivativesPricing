#ifndef BS_CALL_CLASS_HPP
#define BS_CALL_CLASS_HPP

class BSCall
{
private:
    double r;
    double d;
    double T;
    double Spot;
    double Strike;
    
public:
    BSCall(double r_, double d_, double T_, double Spot_, double Strike_);
    double operator()(double Vol) const;
};

#endif