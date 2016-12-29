#pragma once
#include "iobserver.h"
#include <iostream>
using std::string;
class CBObserver :
	public IObserver
{
public:
	CBObserver(void);
	~CBObserver(void);
	void Update(string context);
	string GetName();
private:
	void Work(string report);
};