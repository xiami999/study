#include "simplefactory_ui.h"
#include "simplefactory.h"
#include <iostream>
void CosmeticDisplay::display()
{
	Cosmetic *pCosmetic = CosmeticFactory::productCosmetic(CosmeticFactory::FACIALCLEANSER);
	if (pCosmetic)
	{
		std::string strResult;
		pCosmetic->smear(strResult);
		std::cout << strResult << std::endl;
		delete pCosmetic;
		pCosmetic = NULL;
	}

	pCosmetic = CosmeticFactory::productCosmetic(CosmeticFactory::MAKEUPWATER);
	if (pCosmetic)
	{
		std::string strResult;
		pCosmetic->smear(strResult);
		std::cout << strResult << std::endl;
		delete pCosmetic;
		pCosmetic = NULL;
	}
}