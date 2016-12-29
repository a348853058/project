#include "Command.cpp"  

//模拟输入字符串,然后对输入的字符串进行undo redo操作  
//你可以打开有undo redo功能的文本编辑程序测试是否是这样  
//这里记录的是完整记录,即:即便在undo 或 redo 过程中又发生数据改变  
//也会记录,如果不想这样在undo 或者 redo 输入新字符串时 将redo清空即可  
//即认为在历史记录中修改值被认为是最新的值，不需要再redo  
int main()
{
	//默认没有输入字符串可以是空，这里为了演示赋值一个特殊的字符串  
	Commander *p = new Commander(new InputCommand("[empty]"));
	//输入1111  
	p->ExecuteCommand(new InputCommand("1111"));
	//输入5555  
	p->ExecuteCommand(new InputCommand("5555"));
	//输入aaa  
	p->ExecuteCommand(new InputCommand("aaa"));
	//执行一次undo 撤销到 5555  
	p->Undo();
	//执行一次undo 撤销到 1111  
	p->Undo();
	//undo后中间输入新字符串 insert 覆盖 1111  
	p->ExecuteCommand(new InputCommand("xxxx"));
	//执行一次undo 撤销到 1111  
	p->Undo();
	//执行一次undo 撤销到最初情况 [empty]  
	p->Undo();
	//执行失败已经undo 到最原始情况  
	p->Undo();
	//执行一次redo 重做到 1111  
	p->Redo();
	//执行一次redo 重做到 xxxx  
	p->Redo();
	//执行一次redo 重做到 5555  
	p->Redo();
	//redo后中间输入新字符串 bbbb 覆盖 5555  
	p->ExecuteCommand(new InputCommand("bbbb"));
	//执行一次undo 撤销到5555  
	p->Undo();
	//执行一次redo 重做到 bbbb  
	p->Redo();
	//执行一次redo 重做到 aaa 
	p->Redo();
	//执行失败已经redo 到最新情况  
	p->Redo();
	delete p;
	return 0;
}