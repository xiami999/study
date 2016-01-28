#include "publish_subscribe_client.h"
void PulishSubscribeDisplay::display()
{
	PETeacher peTeacher;
	MathTeacher mathTeacher;

	std::string xiaoming("xiaoming");
	IObserver* pStudentXM = new Student(xiaoming);
	peTeacher.addObserver(pStudentXM);
	mathTeacher.addObserver(pStudentXM);

	std::string hanmm("hanmeimei");
	IObserver* pStudentHMM = new Student(hanmm);
	peTeacher.addObserver(pStudentHMM);
	mathTeacher.addObserver(pStudentHMM);

	std::string zhangsan("zhangsan");
	IObserver* pAttendanceZS = new Attendance(zhangsan);
	peTeacher.addObserver(pAttendanceZS);
	mathTeacher.addObserver(pAttendanceZS);

	mathTeacher.removeObserver(pStudentHMM);

	mathTeacher.goToClass();
	peTeacher.goToClass();

	if (pStudentHMM)
		delete pStudentHMM;

	if (pStudentXM)
		delete pStudentXM;

	if (pAttendanceZS)
		delete pAttendanceZS;
}
