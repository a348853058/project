// Observer.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "BossObservable.h"
#include "AObserver.h"
#include "BObserver.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;


void DoNew()
{
	IObserver *pA = new CAObserver();
	IObserver *pB = new CBObserver();

	CBossObservable *pBoss = new CBossObservable();

	pBoss->AddObserver(pA);
	pBoss->AddObserver(pB);
	pBoss->Check();

	delete pA;
	pA = NULL;
	delete pBoss;
	pBoss = NULL;
}


int main()
{
	DoNew();
	system("pause");
	return 0;
}