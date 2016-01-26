#ifndef FACTORY_H
#define FACTORY_H
#include "../simplefactory/simplefactory.h"
class CosmeticFactory2
{
public:
	virtual Cosmetic* productCosmetic() = 0;
};

class FacialCleanserFactory : public CosmeticFactory2
{
public:
	virtual Cosmetic* productCosmetic();
};

class FacialMaskFactory : public CosmeticFactory2
{
public:
	virtual Cosmetic* productCosmetic();
};

class MakeupWaterFactory : public CosmeticFactory2
{
public:
	virtual Cosmetic* productCosmetic();
};

class LotionFactory : public CosmeticFactory2
{
public:
	virtual Cosmetic* productCosmetic();
};

class FacicalMoisturizerFactory : public CosmeticFactory2
{
public:
	virtual Cosmetic* productCosmetic();	
};
#endif //FACTORY_H