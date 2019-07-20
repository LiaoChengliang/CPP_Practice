#include<iostream>
using namespace std;

struct BitNode
{
	int data;
    BitNode *lchild, *rchild;
};
class Stack{
	BitNode *stack[100];
	int length;
public:
	Stack(){
		length = 0;
	}
	void push(BitNode *bn)
	{
		if (length < 100)
		{
			stack[length] = bn;
			length++;
		}
	}
	BitNode *pop()
	{
		if (length > 0)
		{
			length--;
		}
		return stack[length];
	}
	bool isEmpty()
	{
		if (length == 0)
		{
			return true;
		}
		else
			return false;
	}
};
class Queue
{
	BitNode *queue[100];
	int length;
public:
	Queue(){
		length = 0;
	}
	void EnQueue(BitNode *bn)
	{
		if (length < 100)
		{
			queue[length] = bn;
			length++;
		}
	}
	BitNode *DeQueue()
	{	
		BitNode *nd = queue[0];
		if (length > 0)
		{
			for (int i = 0; i < length-1;i++)
			{
				queue[i] = queue[i+ 1] ;	
			}	
			length--;
		}	
		return nd;
	}
	
	bool isEmpty()
	{
		if (length == 0)
		{
			return true;
		}
		else
			return false;
	}
};
BitNode *CreateTree(BitNode *parent);//按先序输入，后继为空输入0；
void Fsearch(BitNode *parent);//先序遍历
void Msearch(BitNode *parent);//中序遍历
void Lsearch(BitNode *parent);//后序遍历
void Gsearch(BitNode *parent);//层次遍历
void Nre_Msearch(BitNode *parent);//非递归遍历
void main()
{
	BitNode *parent=new BitNode();
	cout << "按先序输入，后继为空输入0；"<<endl;
	parent=CreateTree(parent);

	while (1)
	{
		int option;
		cout<< "输入遍历方式："<<endl;
		cout << "1.先序遍历" << endl;
		cout << "2.中序遍历" << endl;
		cout << "3.后序遍历" << endl;
		cout << "4.层次遍历" << endl;
		cout << "5.非递归中序遍历" << endl;
		cin >> option;
		switch (option)
		{
		case 1:Fsearch(parent); break;
		case 2:Msearch(parent); break;
		case 3:Lsearch(parent); break;
		case 4:Gsearch(parent); break;
		case 5:Nre_Msearch(parent); break;
		}
	}
	system("pause");
	
}
BitNode *CreateTree(BitNode *parent)
{	
	parent = new BitNode();
	int temp;
	cin >> temp;
	if (temp != 0)
	{
		parent->data = temp;
		parent->lchild = CreateTree(parent->lchild);
		parent->rchild = CreateTree(parent->rchild);
	}
	else
	parent=NULL;	
	return parent;
}
void Fsearch(BitNode *parent)//先序遍历
{
	cout << parent->data<<" ";
	if (parent->lchild != NULL)
	{
		Fsearch(parent->lchild);
	}
	if (parent->rchild != NULL)
	{
		Fsearch(parent->rchild);
	}
}
void Msearch(BitNode *parent)//中序遍历
{
	
	if (parent->lchild != NULL)
	{
		Msearch(parent->lchild);
	}
	cout << parent->data << " ";
	if (parent->rchild != NULL)
	{
		Msearch(parent->rchild);
	}
}
void Lsearch(BitNode *parent)//后序遍历
{
	if (parent->lchild != NULL)
	{
		Lsearch(parent->lchild);
	}
	if (parent->rchild != NULL)
	{
		Lsearch(parent->rchild);
	}
	cout << parent->data << " ";
}
void Gsearch(BitNode *parent)
{
	Queue Q;
	BitNode *p;
	Q.EnQueue(parent);
	while (!Q.isEmpty()){
		p=Q.DeQueue();
		cout << p->data<<" ";
		if (p->lchild != NULL)
			Q.EnQueue(p->lchild);
		if (p->rchild != NULL) 
			Q.EnQueue(p->rchild); 
	}	
}
void Nre_Msearch(BitNode *parent)
{
	Stack S;
	BitNode *p = parent;
	while (p ||!S.isEmpty())
	{
		if (p)
		{
			S.push(p);
			p = p->lchild;
		}
		else
		{
			p=S.pop();
			cout << p->data<<" ";
			p = p->rchild;
		}
	}
}