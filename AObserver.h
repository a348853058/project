#pragma once
#include "iobserver.h"
#include <iostream>
using std::string;
class CAObserver :
	public IObserver
{
public:
	CAObserver(void);
	~CAObserver(void);
	void Update(string context);
	string GetName();
private:
	void ReportToOthers(string report);
};