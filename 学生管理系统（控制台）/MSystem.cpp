#include "MSystem.h"
#include<iostream>
#include<string>
System::System()//���캯��
{
	Length = 0;
}
void System::Operate()
{
	std::cout << "------------��ѡ�����²���-------------" << std::endl;
	std::cout << "------------1.���ѧ��-----------------" << std::endl;
	std::cout << "------------2.��ʾ����ѧ����Ϣ---------" << std::endl;
	std::cout << "------------3.ɾ��---------------------" << std::endl;
	std::cout << "------------4.�޸�---------------------" << std::endl;
	std::cout << "------------5.����---------------------" << std::endl;
	std::cout << "------------6.����---------------------" << std::endl;
	std::cout << "------------7.�˳�ϵͳ-----------------" << std::endl;
	std::cout << "���������";
}
void System::Add()//���ѧ��
{
	std::cout << "���ѧ��������";
	int num;
	std::cin >> num;
	for (int i = Length; i <Length + num; i++)
	{
		std::cout << "�����" << i + 1 << "��ѧ��������";
		std::cin >> student[i].name;
		std::cout << "ѧ�ţ�";
		std::cin >> student[i].number;
		std::cout << "�ɼ���";
		std::cin >> student[i].score;
	}
	Length = Length + num;
}
void System::Show()//��ʾ������Ϣ
{
	for (int i = 0; i < Length; i++)
	{
		std::cout << i + 1 << ".����:" << student[i].name << "	ѧ��:" << student[i].number << "	�ɼ�:" << student[i].score << std::endl;
	}
}
void System::Delete()//ɾ��ѧ��
{
	std::cout << "��Ҫɾ���ڼ���ѧ����";
	int num;
	std::cin >> num;
	for (int i = num - 1; i < Length - 1; i++)
	{
		student[i] = student[i + 1];
	}
	if (Length> 0)
	{
		Length = Length - 1;
		std::cout << "��ɾ����" << std::endl;
	}

}
void System::Modify()//�޸�ѧ����Ϣ
{
	std::cout << "��Ҫ�޸ĵڼ���ѧ����Ϣ��";
	int num;
	std::cin >> num;
	std::cout << "�����" << num << "��ѧ��������";
	std::cin >> student[num - 1].name;
	std::cout << "ѧ�ţ�";
	std::cin >> student[num - 1].number;
	std::cout << "�ɼ���";
	std::cin >> student[num - 1].score;
	std::cout << "���޸ģ�";
}
void System::Sort()//����
{
	std::cout << "1.��ѧ������  2.���ɼ�����" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1:NumberSort(); break;
	case 2:ScoreSort(); break;
	}
	std::cout << "�������\n";
}
void System::Search()//����
{
	std::cout << "1.��ѧ�Ų���   2.����������" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1:NumberSearch(); break;
	case 2:NameSearch(); break;
	}
}
void System::NumberSort()//��ѧ������
{
	for (int i = 0; i < Length - 1; i++)
	{
		for (int j = i + 1; j < Length; j++)
		{
			if (student[i].number >student[j].number)
			{
				Student t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
		}
	}
}
void System::ScoreSort()//���ɼ�����
{
	for (int i = 0; i < Length - 1; i++)
	{
		for (int j = i + 1; j < Length; j++)
		{
			if (student[i].score < student[j].score)
			{
				Student t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
		}
	}
}
void System::NumberSearch()//��ѧ�Ų���
{
	std::cout << "������ѧ�ţ�";
	double num;
	std::cin >> num;
	for (int i = 0; i < Length; i++)
	{
		if (student[i].number == num)
		{
			std::cout << "����:" << student[i].name << "	ѧ��:" << student[i].number << "	�ɼ�:" << student[i].score << std::endl;
			return;
		}
	}
	std::cout << "����ʧ��!" << std::endl;
}
void System::NameSearch()//����������
{
	std::cout << "������������";
	std::string s;
	std::cin >> s;
	for (int i = 0; i <Length; i++)
	{
		if (student[i].name == s)
		{
			std::cout << "����:" << student[i].name << "	ѧ��:" << student[i].number << "	�ɼ�:" << student[i].score << std::endl;
			return;
		}
	}
	std::cout << "����ʧ��!" << std::endl;
}