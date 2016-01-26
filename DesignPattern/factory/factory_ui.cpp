#include "factory_ui.h"
#include "factory.h"
#include <iostream>
void CosmeticFactoryDisplay::display()
{
	CosmeticFactory2* pCosmeticFactory = new FacicalMoisturizerFactory;
	Cosmetic *pCosmetic = pCosmeticFactory->productCosmetic();
	if (pCosmetic)
	{
		std::string strResult;
		pCosmetic->smear(strResult);
		std::cout << strResult << std::endl;
		delete pCosmetic;
		pCosmetic = NULL;
	}

	if (pCosmeticFactory)
		delete pCosmetic;

	pCosmeticFactory = new LotionFactory;
	pCosmetic = pCosmeticFactory->productCosmetic();
	if (pCosmetic)
	{
		std::string strResult;
		pCosmetic->smear(strResult);
		std::cout << strResult << std::endl;
		delete pCosmetic;
		pCosmetic = NULL;
	}

	if (pCosmeticFactory)
		delete pCosmetic;
}