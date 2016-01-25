#ifndef STRATEGY_UI_H
#define STRATEGY_UI_H
#include "strategy.h"
#include <string>
class Cashier
{
public:
	Cashier();
	void sum(std::string& name, double price, int number);
	double getResult(int type);
	std::string& getBill();
protected:
	std::string m_bill;
	double m_total;
};

class CashierDisplay
{
public:
	void display();

protected:
	void cash();
	void getResult(Cashier& cashier);
};

#endif //STRATEGY_UI_H