#include "strategy.h"
Discount::Discount(double dicount) : m_discount(dicount)
{
}

double Discount::getResult(double amount)
{
	return amount * m_discount;
}


double Nomal::getResult(double amount)
{
	return amount;
}

Rebate::Rebate(double condition, double rebate)
	: m_condition(condition), m_rebate(rebate)
{
}

double Rebate::getResult(double amount)
{
	if (amount >= m_condition)
		return amount - m_rebate;
	
	return amount;
}

CashContext::CashContext() : m_pCash(nullptr)
{

}

CashContext::CashContext(CASHTYPE cashtype)
{
	switch (cashtype)
	{
	case NormalCashType:
		m_pCash = new Nomal();
		break;
	case DiscountCashType:
		m_pCash = new Discount(0.8);
		break;
	case RebateCashType:
		m_pCash = new Rebate(300, 20);
		break;
	default:
		m_pCash = nullptr;
		break;
	}

}

CashContext::~CashContext()
{
	if (m_pCash)
		delete m_pCash;
}

double CashContext::getResult(double amount)
{
	if (!m_pCash)
		return 0.0;

	return m_pCash->getResult(amount);
}
