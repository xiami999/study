#include "memo_client.h"
#include <iostream>
using namespace std;

void MemoDisplay::Display()
{
	Fencer susu;
	ShowState(susu);

	susu.SetEnergy(2500);
	susu.SetWealth(600);
	susu.SetSens(3000);
	ShowState(susu);

	Caretaker caretaker;
	caretaker.SetMemo(susu.CreateMemo());
	
	susu.SetEnergy(6000);
	susu.SetWealth(7000);
	susu.SetSens(100);
	susu.SetEssence(20000);
	ShowState(susu);

	susu.SetMemo(caretaker.GetMemo());
	ShowState(susu);
}

void MemoDisplay::ShowState(Fencer& role)
{
	cout << "Essence: " << role.GetEssence() << endl;
	cout << "Sens: " << role.GetSens() << endl;
	cout << "Wealth: " << role.GetWealth() << endl;
	cout << "Energy: " << role.GetEnergy() << endl;
}
