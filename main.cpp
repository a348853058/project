#include "Command.cpp"  

//ģ�������ַ���,Ȼ���������ַ�������undo redo����  
//����Դ���undo redo���ܵ��ı��༭��������Ƿ�������  
//�����¼����������¼,��:������undo �� redo �������ַ������ݸı�  
//Ҳ���¼,�������������undo ���� redo �������ַ���ʱ ��redo��ռ���  
//����Ϊ����ʷ��¼���޸�ֵ����Ϊ�����µ�ֵ������Ҫ��redo  
int main()
{
	//Ĭ��û�������ַ��������ǿգ�����Ϊ����ʾ��ֵһ��������ַ���  
	Commander *p = new Commander(new InputCommand("[empty]"));
	//����1111  
	p->ExecuteCommand(new InputCommand("1111"));
	//����5555  
	p->ExecuteCommand(new InputCommand("5555"));
	//����aaa  
	p->ExecuteCommand(new InputCommand("aaa"));
	//ִ��һ��undo ������ 5555  
	p->Undo();
	//ִ��һ��undo ������ 1111  
	p->Undo();
	//undo���м��������ַ��� insert ���� 1111  
	p->ExecuteCommand(new InputCommand("xxxx"));
	//ִ��һ��undo ������ 1111  
	p->Undo();
	//ִ��һ��undo ������������ [empty]  
	p->Undo();
	//ִ��ʧ���Ѿ�undo ����ԭʼ���  
	p->Undo();
	//ִ��һ��redo ������ 1111  
	p->Redo();
	//ִ��һ��redo ������ xxxx  
	p->Redo();
	//ִ��һ��redo ������ 5555  
	p->Redo();
	//redo���м��������ַ��� bbbb ���� 5555  
	p->ExecuteCommand(new InputCommand("bbbb"));
	//ִ��һ��undo ������5555  
	p->Undo();
	//ִ��һ��redo ������ bbbb  
	p->Redo();
	//ִ��һ��redo ������ aaa 
	p->Redo();
	//ִ��ʧ���Ѿ�redo ���������  
	p->Redo();
	delete p;
	return 0;
}