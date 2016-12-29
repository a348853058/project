#pragma once
#include "CorpNode.h"
#include <vector>
#include <iostream>
using std::vector;
using std::string;
class CBranchNode :
	public CCorpNode
{
public:
	CBranchNode(void);
	CBranchNode(string name, string pos, int salary);
	~CBranchNode(void);
	void Add(CCorpNode *pcorpNode);
	vector<CCorpNode*> GetSubordinateInfo();
	bool IsLeaf();
private:
	vector<CCorpNode*> m_subordinateList;
};