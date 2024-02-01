#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "Random2.hpp"
#include "Wrapper.hpp"

class AntiThetic : public RandomBase
{
private:
	Wrapper<RandomBase> InnerGenerator;
	bool OddEven;
	MJArray NextVariates;
public:
	AntiThetic(const Wrapper<RandomBase>& innerGenerator);
	virtual RandomBase* clone() const;
	virtual void GetUniforms(MJArray& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void ResetDimensionality(unsigned long NewDimensionality);
	virtual void Reset();
};





#endif

