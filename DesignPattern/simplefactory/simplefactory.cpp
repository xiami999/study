#include "simplefactory.h"

Cosmetic* CosmeticFactory::productCosmetic(CosmeticType type)
{
	switch(type)
	{
	case FACIALCLEANSER:
		return new FacialCleanser;
	case FACICALMASK:
		return new FacialMask;
	case LOTION:
		return new Lotion;
	case MAKEUPWATER:
		return new MakeupWater;
	case FACICALMOISTURIZER:
		return new FacicalMoisturizer;
	default:
		return NULL;
	}
}

void FacialCleanser::smear(std::string& strResult)
{
	strResult.assign("Deep clean the skin.");
}

void FacialMask::smear(std::string& strResult)
{
	strResult.assign("contracting the pores.");
}

void Lotion::smear(std::string& strResult)
{
	strResult.assign("lotion.");
}

void MakeupWater::smear(std::string& strResult)
{
	strResult.assign("hydrate the skin.");
}

void FacicalMoisturizer::smear(std::string& strResult)
{
	strResult.assign("Moisturizer");
}
