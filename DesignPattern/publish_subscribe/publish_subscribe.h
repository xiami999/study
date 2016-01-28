#ifndef PUBLISH_SUBSCRIBE_H
#define PUBLISH_SUBSCRIBE_H
#include <string>
#include <set>
class IObserver
{
public:
	virtual void update(std::string& name) = 0;
};

class Observer : public IObserver
{
public:
	Observer(std::string& name);
	virtual void update(std::string& name);
protected:
	std::string m_name;
};

class Student : public Observer
{
public:
	Student(std::string& name);
	virtual void update(std::string& name);
};

class Attendance : public Observer
{
public:
	Attendance(std::string& name);
	virtual void update(std::string& name);
};

class ISubeject
{
public:
	virtual void addObserver(IObserver* pObserver) = 0;
	virtual void removeObserver(IObserver* pObserver) = 0;
	virtual void notify(std::string& msg) = 0;
};

class Teacher : public ISubeject
{
public:
	virtual void addObserver(IObserver* pObserver);
	virtual void removeObserver(IObserver* pObserver);
	virtual void notify(std::string& msg);
	virtual void goToClass();
protected:
	std::set<IObserver*> m_ObserverSet;
};

class PETeacher : public Teacher
{
public:
	void goToClass();
};

class MathTeacher : public Teacher
{
public:
	void goToClass();
};
#endif //PUBLISH_SUBSCRIBE_H