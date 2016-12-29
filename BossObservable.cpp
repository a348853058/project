#include "StdAfx.h"
#include "BossObservable.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
CBossObservable::CBossObservable(void)
{
}
CBossObservable::~CBossObservable(void)
{
}
void CBossObservable::AddObserver(IObserver *pObserver)
{
	m_observerList.push_back(pObserver);
}
void CBossObservable::DeleteObserver(IObserver *pObserver)
{
	ObserverList_C_iterator it = m_observerList.begin();
	for (; it != m_observerList.end(); it++)
	{
		string name = (*it)->GetName();
		if (name.compare(pObserver->GetName()) == 0)
		{
			//�ҵ���ɾ����
		}
	}
}
void CBossObservable::NotifyObservers(string context)
{
	ObserverList_C_iterator it = m_observerList.begin();
	for (; it != m_observerList.end(); it++)
	{
		(*it)->Update(context);
	}
}
void CBossObservable::Check()
{
	cout << "�ϰ�:Ѳ��Ա���������..." << endl;

	this->NotifyObservers("�ϰ�Ѳ�ӹ���");
}
