#ifndef EXOTIC_BS_ENGINE_H
#define EXOTIC_BS_ENGINE_H
#include "ExoticEngine.hpp"
#include "Random2.hpp"

class ExoticBSEngine : public ExoticEngine
{
private:
    Wrapper<RandomBase> TheGenerator;
    MJArray Drifts;
    MJArray StandardDerivations;
    double LogSpot;
    unsigned long NumberOfTimes;
    MJArray Variates;
public:
    ExoticBSEngine(
        const Wrapper<PathDependent>& TheProduct_,
        const Parameters& R_,
        const Parameters& D_,
        const Parameters& Vol_,
        const Wrapper<RandomBase>& TheGenerator_,
        double Spot_
        );
    virtual void GenOnePath(MJArray& SpotValues);
    virtual ~ExoticBSEngine(){}
};




#endif