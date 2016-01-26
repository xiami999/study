#include "factory.h"

Cosmetic* FacialCleanserFactory::productCosmetic()
{
	return new FacialCleanser;
}

Cosmetic* FacialMaskFactory::productCosmetic()
{
	return new FacialMask;
}

Cosmetic* MakeupWaterFactory::productCosmetic()
{
	return new MakeupWater;
}

Cosmetic* LotionFactory::productCosmetic()
{
	return new Lotion;
}

Cosmetic* FacicalMoisturizerFactory::productCosmetic()
{
	return new FacicalMoisturizer;
}
