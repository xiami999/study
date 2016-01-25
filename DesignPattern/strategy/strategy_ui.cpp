#include "strategy_ui.h"
#include <iostream>
#include <stdio.h>

void CashierDisplay::display()
{
	int action = 0;
	do 
	{
		std::cout << "\nWelcome to the cash register system!" << std::endl;
		std::cout << "1. exit\n2.new bill" << std::endl;

		action = 0;
		std::cin >> action;
		std::cin.sync();
		if (std::cin.good())
		{
			if (2 == action)
				cash();
		}
		else if (std::cin.fail())
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
		}
		else
		{
			break;
		}

	} while (1 != action);
}

void CashierDisplay::cash()
{
	Cashier cashier;
	int action = 0;
	do 
	{
		std::cout << "1. exit.\n2.new goods." << std::endl;
		action = 0;
		std::cin >> action;
		std::cin.sync();
		if (std::cin.fail())
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			continue;
		}
		else if (1 == action)
		{
			break;
		}

		std::string name;
		std::cout << "name = ";
		std::cin >> name;
		std::cin.sync();
		if (std::cin.fail())
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			continue;
		}

		double price = 0.0;
		std::cout << "price = ";
		std::cin >> price;
		std::cin.sync();
		if (std::cin.fail())
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			continue;
		}

		int number = 0;
		std::cout << "number = ";
		std::cin >> number;
		std::cin.sync();
		if (std::cin.fail())
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			continue;
		}

		cashier.sum(name, price, number);
	} while (true);

	getResult(cashier);
	
	std::string strBill = cashier.getBill();
	std::cout << strBill << std::endl;
}

void CashierDisplay::getResult(Cashier& cashier)
{
	int action = 0;
	do 
	{
		std::cout << "Please select a business:" << std::endl;
		std::cout << "1. No Concessions\n"
			<< "2. offer a twenty per cent discount\n"
			<< "3. If greater than $300 to $20" << std::endl;
		
		action = 0;
		std::cin >> action;
		std::cin.sync();
		if (std::cin.good())
		{
			if (0 < action && 4 > action)
			{
				std::cout << "Total receivables: " << cashier.getResult(action) << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
		}

	} while (true);
}

Cashier::Cashier() : m_total (0.0)
{
	m_bill.assign("name\tprice\tnumber\n");
}

void Cashier::sum(std::string& name, double price, int number)
{
	m_total += price * number;
	char buf[256];
	int len = sprintf_s(buf, sizeof(buf), "%s\t%0.2f\t%d\n", name.c_str(), price, number);
	if (len > 0)
		m_bill.append(buf, len);
}

double Cashier::getResult(int type)
{
	CashContext::CASHTYPE cashType = CashContext::NormalCashType;
	switch (type)
	{
	case CashContext::DiscountCashType:
		cashType = CashContext::DiscountCashType;
		break; 
	case CashContext::RebateCashType:
		cashType = CashContext::RebateCashType;
		break;
	default:
		cashType = CashContext::NormalCashType;		
	}

	CashContext cashContext(cashType);
	double result =  cashContext.getResult(m_total);

	char buf[256];
	int len = sprintf_s(buf, sizeof(buf), 
		"Total: %0.2f\nPreferential: %0.2f\nTotal receivables: %0.2f",
		m_total, m_total - result, result);

	if (len > 0)
		m_bill.append(buf, len);

	return result;
}

std::string& Cashier::getBill()
{
	return m_bill;
}
