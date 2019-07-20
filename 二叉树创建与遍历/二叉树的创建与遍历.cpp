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
BitNode *CreateTree(BitNode *parent);//���������룬���Ϊ������0��
void Fsearch(BitNode *parent);//�������
void Msearch(BitNode *parent);//�������
void Lsearch(BitNode *parent);//�������
void Gsearch(BitNode *parent);//��α���
void Nre_Msearch(BitNode *parent);//�ǵݹ����
void main()
{
	BitNode *parent=new BitNode();
	cout << "���������룬���Ϊ������0��"<<endl;
	parent=CreateTree(parent);

	while (1)
	{
		int option;
		cout<< "���������ʽ��"<<endl;
		cout << "1.�������" << endl;
		cout << "2.�������" << endl;
		cout << "3.�������" << endl;
		cout << "4.��α���" << endl;
		cout << "5.�ǵݹ��������" << endl;
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
void Fsearch(BitNode *parent)//�������
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
void Msearch(BitNode *parent)//�������
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
void Lsearch(BitNode *parent)//�������
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