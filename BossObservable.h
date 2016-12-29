#pragma once
#include "iobservable.h"
#include "IObserver.h"
#include <vector>
using std::vector;
class CBossObservable :
	public IObservable
{
public:
	CBossObservable(void);
	~CBossObservable(void);
	void AddObserver(IObserver *pObserver);
	void DeleteObserver(IObserver *pObserver);
	void NotifyObservers(string context);
	void Check();
private:
	vector<IObserver*> m_observerList;
	typedef vector<IObserver*>::const_iterator ObserverList_C_iterator;
};