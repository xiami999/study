#include "memo.h"
#include <assert.h>
#include <stdlib.h>
RoleState::RoleState(RoleState& state)
{
	m_essence = state.m_essence;
	m_energy = state.m_energy;
	m_sens = state.m_sens;
}

RoleState::RoleState()
	: m_essence(DEFAULTSTATE), m_sens(DEFAULTSTATE), m_energy(DEFAULTSTATE)
{}

RoleState::RoleState(int essence, int sens, int energy)
	: m_essence(essence), m_sens(sens), m_energy(energy)
{}

int RoleState::GetEssence()
{
	return m_essence;
}

void RoleState::SetEssence(int essence)
{
	m_essence = essence;
}

int RoleState::GetSens()
{
	return m_sens;
}

void RoleState::SetSens(int sens)
{
	m_sens = sens;
}

int RoleState::GetEnergy()
{
	return m_energy;
}

void RoleState::SetEnergy(int energy)
{
	m_energy = energy;
}

Memo::Memo(RoleState& state) : m_pState()
{
	m_pState = new RoleState(state);
}

Memo::~Memo()
{
	if (m_pState)
		delete m_pState;
}

RoleState& Memo::GetState()
{
	return *m_pState;
}

Memo* Fencer::CreateMemo()
{
	return new Memo(*m_pState);
}

Fencer::Fencer() : m_pState(new RoleState), m_Wealth(DEFAULT_WEALTH)
{
}

Fencer::Fencer(int essence, int sens, int energy, int wealth)
	: m_pState(new RoleState(essence, sens, energy)), m_Wealth(wealth)
{}

Fencer::~Fencer()
{
	if (m_pState)
		delete m_pState;
}

void Fencer::SetMemo(Memo* pMemo)
{
	assert(pMemo);
	if (m_pState)
		delete m_pState;
	m_pState = new RoleState(pMemo->GetState());
}

int Fencer::GetEssence()
{
	return m_pState->GetEssence();
}

void Fencer::SetEssence(int essence)
{
	m_pState->SetEssence(essence);
}

int Fencer::GetSens()
{
	return m_pState->GetSens();
}

void Fencer::SetSens(int sens)
{
	m_pState->SetSens(sens);
}

int Fencer::GetEnergy()
{
	return m_pState->GetEnergy();
}

void Fencer::SetEnergy(int energy)
{
	m_pState->SetEnergy(energy);
}

void Fencer::SetWealth(int wealth)
{
	m_Wealth = wealth;
}

int Fencer::GetWealth()
{
	return m_Wealth;
}


void Caretaker::SetMemo(Memo* pMemo)
{
	assert(pMemo);
	m_pMemo = pMemo;
}

Memo* Caretaker::GetMemo()
{
	return m_pMemo;
}

Caretaker::Caretaker() : m_pMemo(NULL)
{

}

Caretaker::~Caretaker()
{
	if (m_pMemo)
		delete m_pMemo;
}
