#ifndef Parameters_HPP
#define Parameters_HPP

class ParametersInner
{
private:
    /* data */
public:
    virtual ParametersInner* clone() const=0;
    virtual double Integral(double time1, double time2) const=0;
    virtual double IntegralSquare(double time1, double time2) const=0;
    virtual ~ParametersInner(){};
};


class Parameters
{
private:
    ParametersInner* InnerObjectPtr;
public:
    Parameters(const ParametersInner& innerObject);
    Parameters(const Parameters& original);
    Parameters& operator=(const Parameters& original);
    virtual ~Parameters();

    inline double Integral(double time1, double time2) const;
    inline double IntegralSquare(double time1, double time2) const;
    double Mean(double time1, double time2) const;
    double RootMeanSquare(double time1, double time2) const;
};


inline double Parameters::Integral(double time1, double time2) const{
    return InnerObjectPtr->Integral(time1, time2);
}

inline double Parameters::IntegralSquare(double time1, double time2) const{
    return InnerObjectPtr->IntegralSquare(time1, time2);
}


class ParametersConstant: public ParametersInner{
private:
    double Constant;
    double ConstantSquare;
public:
    ParametersConstant(double constant);
    virtual ParametersInner* clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
};





#endif