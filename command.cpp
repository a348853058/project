#include <iostream>  
#include <stack>  
#include <string>  
using std::cout;
using std::endl;

class Command
{
public:
	Command() 
	{
	}
	virtual ~Command()
	{
	}
	virtual void Execute() = 0;
};


class InputCommand : public Command
{
public:

	InputCommand(const std::string &input)
	{
		mInput = input;
	}
	~InputCommand()
	{
	}
	void Execute()
	{
		cout << "current string:" << mInput<<endl;
	}

private:
	std::string mInput;
};

class Commander
{
public:
	Commander(Command *pCmd)
	{
		//�������������  
		mUndo.push(pCmd);
	}
	~Commander()
	{
		while (false == mUndo.empty())
		{
			delete mUndo.top();
			mUndo.pop();
		}
		while (false == mRedo.empty())
		{
			delete mRedo.top();
			mRedo.pop();
		}
	}

	void ExecuteCommand(Command *pCmd)
	{
		pCmd->Execute();
		mUndo.push(pCmd);
	}

	void Undo()
	{
		if (mUndo.size() < 2)
		{
			//�޷����˳���û������  
			cout<<"undo failed."<<endl;
			return;
		}
		cout<<"undo:" << endl;
		//��ǰ����  
		auto pCmd = mUndo.top();
		//���浱ǰ����  
		mRedo.push(pCmd);
		//����  
		mUndo.pop();
		//��ԭ���ϸ�����  
		pCmd = mUndo.top();

		pCmd->Execute();
	}

	void Redo()
	{
		if (mRedo.empty())
		{
			//�޷�ǰ������û������  
			cout<<"redo failed." << endl;
			return;
		}
		cout<<"redo:" << endl;
		auto pCmd = mRedo.top();
		pCmd->Execute();
		mRedo.pop();
		mUndo.push(pCmd);
	}
private:
	std::stack< Command* > mUndo;
	std::stack< Command* > mRedo;
};