#include "StdAfx.h"
#include "CorpNode.h"
CCorpNode::CCorpNode(void)
{
	m_name = "";
	m_position = "";
	m_salary = 0;
}
CCorpNode::CCorpNode(string _name, string _pos, int _salary) : m_name(_name), m_position(_pos), m_salary(_salary)
{
}
CCorpNode::~CCorpNode(void)
{
}
string CCorpNode::GetInfo()
{
	string info = "";
	info.append("������");
	info.append(this->m_name);
	info.append("\tְλ��");
	info.append(this->m_position);
	info.append("\tнˮ��");
	char buf[50] = { 0 };
	sprintf_s(buf, "%d", this->m_salary);
	info.append(buf);
	return info;
}
void CCorpNode::SetParent(CCorpNode *_parent)
{
	this->m_pParent = _parent;
}
CCorpNode * CCorpNode::GetParent()
{
	return this->m_pParent;
}