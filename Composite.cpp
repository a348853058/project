// Composite.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include "BranchNode.h"
#include "LeafNode.h"
#include <vector>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::endl;

string GetTreeInfo(CBranchNode * proot)
{
	vector<CCorpNode*> subordinateList = proot->GetSubordinateInfo();
	string info = "";

	vector<CCorpNode*>::const_iterator it = subordinateList.begin();
	for (; it != subordinateList.end(); it++)
	{
		if ((*it)->IsLeaf())
		{
			info.append((*it)->GetInfo());
			info.append("\n");
		}
		else
		{
			info.append((*it)->GetInfo());
			info.append("\n");
			info.append(GetTreeInfo(dynamic_cast<CBranchNode*>(*it)));
		}
	}
	return info;
}


void DoNew()
{
	CBranchNode root("赵", "总经理", 100000);

	CBranchNode devDep("孙", "研发部门经理", 30000);
	CBranchNode artDep("李", "美工部门经理", 20000);
	CBranchNode serDep("周", "客服部门经理", 30000);

	CBranchNode devGroup("郑", "研发组组长", 5000);
	CBranchNode debugGroup("王", "调试组组长", 8000);

	CLeafNode a("冯", "研发人员A", 3500);
	CLeafNode b("陈", "研发人员B", 3500);
	CLeafNode c("楮", "研发人员C", 3500);
	CLeafNode d("卫", "调试人员A", 3000);
	CLeafNode e("蒋", "调试人员B", 3100);
	CLeafNode f("沈", "调试人员C", 3200);
	CLeafNode g("韩", "美工人员A", 4000);
	CLeafNode h("杨", "美工人员B", 5000);
	CLeafNode i("朱", "客服人员A", 4000);
	CLeafNode j("秦", "客服人员B", 5000);
	CLeafNode k("钱", "CEO秘书", 20000);
	CLeafNode fujingli("吴", "研发部副经理", 20000);

	root.Add(&k);//总经理有三个部门经理和一个秘书
	root.Add(&devDep);
	root.Add(&artDep);
	root.Add(&serDep);

	devDep.Add(&fujingli);//研发部有一个副经理和两个小组
	devDep.Add(&devGroup);
	devDep.Add(&debugGroup);

	devGroup.Add(&a);
	devGroup.Add(&b);
	devGroup.Add(&c);
	debugGroup.Add(&d);
	debugGroup.Add(&e);
	debugGroup.Add(&f);

	artDep.Add(&g);
	artDep.Add(&h);

	serDep.Add(&i);
	serDep.Add(&j);

	cout << root.GetInfo().c_str() << endl;
	cout << GetTreeInfo(&root).c_str() << endl;
}


int main()
{
	//使用组合模式后的调用。
	DoNew();
	return 0;
}