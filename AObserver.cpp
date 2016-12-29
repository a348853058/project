#include "StdAfx.h"
#include "AObserver.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
CAObserver::CAObserver(void) : IObserver("员工A")
{
}
CAObserver::~CAObserver(void)
{
}
void CAObserver::Update(string context)
{
	cout << "员工A：观察到老板准备巡视工作,告诉其他员工..." << endl;
	this->ReportToOthers(context);
	cout << "员工A：说完后,其他员工认真工作..." << endl;
}
void CAObserver::ReportToOthers(string report)
{
	cout << "员工A：同志们注意了,老板有动作了--->" << report.c_str() << endl;
}
string CAObserver::GetName()
{
	return m_name;
}