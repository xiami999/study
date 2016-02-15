#ifndef MEMO_H
#define MEMO_H

class RoleState
{
public:
	RoleState();
	RoleState(int essence, int sens, int energy);
	RoleState(RoleState& state);
	int GetEssence();
	void SetEssence(int essence);
	int GetSens();
	void SetSens(int sens);
	int GetEnergy();
	void SetEnergy(int energy);
protected:
	int m_essence;
	int m_sens;
	int m_energy;
	const static int DEFAULTSTATE = 100;
};

class Memo
{
public:
	Memo(RoleState& state);
	~Memo();
	RoleState& GetState();
protected:
	RoleState* m_pState;
};

class Fencer
{
public:
	Fencer();
	Fencer(int essence, int sens, int energy, int wealth);
	~Fencer();
	int GetEssence();
	void SetEssence(int essence);
	int GetSens();
	void SetSens(int sens);
	int GetEnergy();
	void SetEnergy(int energy);
	int GetWealth();
	void SetWealth(int wealth);
	Memo* CreateMemo();
	void SetMemo(Memo* pMemo);
protected:
	RoleState* m_pState;
	int m_Wealth;
	const static int DEFAULT_WEALTH = 1000;
};

class Caretaker
{
public:
	Caretaker();
	~Caretaker();
	void SetMemo(Memo* pMemo);
	Memo* GetMemo();
protected:
	Memo* m_pMemo;
};
#endif //MEMO_H