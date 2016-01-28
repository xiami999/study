#include "publish_subscribe.h"
#include <iostream>
void Teacher::addObserver(IObserver* pObserver)
{
	if (pObserver)
		m_ObserverSet.insert(pObserver);
}

void Teacher::removeObserver(IObserver* pObserver)
{
	if (!pObserver)
		return;

	auto it = m_ObserverSet.find(pObserver);
	if (m_ObserverSet.end() != it)
		m_ObserverSet.erase(it);
}

void Teacher::notify(std::string& msg)
{
	for (auto it = m_ObserverSet.begin(); m_ObserverSet.end() != it; ++it)
		(*it)->update(msg);
}

void Teacher::goToClass()
{
	std::string msg("");
	notify(msg);
}


void PETeacher::goToClass()
{
	std::string msg("PE");
	//to do someting
	notify(msg);
}


void MathTeacher::goToClass()
{
	std::string msg("math");
	//to do someting
	notify(msg);
}

void Observer::update(std::string& msg)
{

}

Observer::Observer(std::string& name)
{
	m_name.assign(name);
}

Student::Student(std::string& name) : Observer(name)
{
	
}

void Student::update(std::string& name)
{
	std::cout << "This is " << name << ".";
	if(0 == name.compare("PE"))
		std::cout << m_name << " go to collection!" << std::endl;
	else
		std::cout << m_name << " listen carefully!" << std::endl;
}

Attendance::Attendance(std::string& name) : Observer(name)
{
}

void Attendance::update(std::string& name)
{
	std::cout << "Excluding the " << name << " absence." << std::endl;
}