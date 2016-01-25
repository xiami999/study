#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H
#include <string>
class Cosmetic
{
public:
	virtual void smear(std::string& strResult) = 0;
};

class FacialCleanser : public Cosmetic
{
public:
	virtual void smear(std::string& strResult);
};

class FacialMask : public Cosmetic
{
public:
	virtual void smear(std::string& strResult);
};

class MakeupWater : public Cosmetic
{
public:
	virtual void smear(std::string& strResult);
};

class Lotion : public Cosmetic
{
public:
	virtual void smear(std::string& strResult);
};

class FacicalMoisturizer : public Cosmetic
{
public:
	virtual void smear(std::string& strResult);
};

class CosmeticFactory
{
public:
	enum CosmeticType 
	{ 
		FACIALCLEANSER, FACICALMASK, LOTION, MAKEUPWATER, FACICALMOISTURIZER
	};

	static Cosmetic* productCosmetic(CosmeticType type);
};
#endif //SIMPLEFACTORY_H