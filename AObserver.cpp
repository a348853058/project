#include "StdAfx.h"
#include "AObserver.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
CAObserver::CAObserver(void) : IObserver("Ա��A")
{
}
CAObserver::~CAObserver(void)
{
}
void CAObserver::Update(string context)
{
	cout << "Ա��A���۲쵽�ϰ�׼��Ѳ�ӹ���,��������Ա��..." << endl;
	this->ReportToOthers(context);
	cout << "Ա��A��˵���,����Ա�����湤��..." << endl;
}
void CAObserver::ReportToOthers(string report)
{
	cout << "Ա��A��ͬ־��ע����,�ϰ��ж�����--->" << report.c_str() << endl;
}
string CAObserver::GetName()
{
	return m_name;
}