#ifndef STRATEGY_H
#define STRATEGY_H
class Cash
{
public:
	virtual double getResult(double amount) = 0;
};

class Discount : public Cash
{
public:
	Discount(double discount);
	virtual double getResult(double amount);
protected:
	double m_discount;
};

class Rebate : public Cash
{
public:
	Rebate(double condition, double rebate);
	virtual double getResult(double amount);
protected:
	double m_condition;
	double m_rebate;
};

class Nomal : public Cash
{
public:
	virtual double getResult(double amount);
};

class CashContext
{
public:
	enum  CASHTYPE{ NormalCashType = 1, DiscountCashType, RebateCashType};
	CashContext();
	CashContext(CASHTYPE cashtype);
	virtual ~CashContext();
	double getResult(double amount);
protected:
	Cash *m_pCash;
};

#endif //STRATEGY_H