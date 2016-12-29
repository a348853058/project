#include "StdAfx.h"
#include "BObserver.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
CBObserver::CBObserver(void) : IObserver("秘书")
{
}
CBObserver::~CBObserver(void)
{
}
void CBObserver::Update(string context)
{
	cout << "秘书：观察到老板准备巡视工作，赶紧藏好正在打游戏的手机..." << endl;
	this->Work(context);
	cout << "秘书：又不能玩手机了..." << endl;
}
void CBObserver::Work(string report)
{
	cout << "秘书：因为" << report.c_str() << ", ————所以我也必须一起巡视啊！" << endl;
}
string CBObserver::GetName()
{
	return m_name;
}