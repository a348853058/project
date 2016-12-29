// Composite.cpp : �������̨Ӧ�ó������ڵ㡣
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
	CBranchNode root("��", "�ܾ���", 100000);

	CBranchNode devDep("��", "�з����ž���", 30000);
	CBranchNode artDep("��", "�������ž���", 20000);
	CBranchNode serDep("��", "�ͷ����ž���", 30000);

	CBranchNode devGroup("֣", "�з����鳤", 5000);
	CBranchNode debugGroup("��", "�������鳤", 8000);

	CLeafNode a("��", "�з���ԱA", 3500);
	CLeafNode b("��", "�з���ԱB", 3500);
	CLeafNode c("��", "�з���ԱC", 3500);
	CLeafNode d("��", "������ԱA", 3000);
	CLeafNode e("��", "������ԱB", 3100);
	CLeafNode f("��", "������ԱC", 3200);
	CLeafNode g("��", "������ԱA", 4000);
	CLeafNode h("��", "������ԱB", 5000);
	CLeafNode i("��", "�ͷ���ԱA", 4000);
	CLeafNode j("��", "�ͷ���ԱB", 5000);
	CLeafNode k("Ǯ", "CEO����", 20000);
	CLeafNode fujingli("��", "�з���������", 20000);

	root.Add(&k);//�ܾ������������ž����һ������
	root.Add(&devDep);
	root.Add(&artDep);
	root.Add(&serDep);

	devDep.Add(&fujingli);//�з�����һ�������������С��
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
	//ʹ�����ģʽ��ĵ��á�
	DoNew();
	return 0;
}