#include "StdAfx.h"
#include "BObserver.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
CBObserver::CBObserver(void) : IObserver("����")
{
}
CBObserver::~CBObserver(void)
{
}
void CBObserver::Update(string context)
{
	cout << "���飺�۲쵽�ϰ�׼��Ѳ�ӹ������Ͻ��غ����ڴ���Ϸ���ֻ�..." << endl;
	this->Work(context);
	cout << "���飺�ֲ������ֻ���..." << endl;
}
void CBObserver::Work(string report)
{
	cout << "���飺��Ϊ" << report.c_str() << ", ��������������Ҳ����һ��Ѳ�Ӱ���" << endl;
}
string CBObserver::GetName()
{
	return m_name;
}