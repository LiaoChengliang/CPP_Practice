#pragma once
#include<iostream>
#include<string>
class Student
{
public:
	std::string name;
	double number;
	int score;
};
class System
{
	Student student[100];
	int Length;
public:
	System();
	void Operate();//������ʾ
	void Add();//���ѧ����Ϣ
	void Show();//��ʾ����ѧ����Ϣ
	void Delete();//ɾ��ѧ��
	void Modify();//�޸�ѧ����Ϣ
	void Sort();//��ѧ����Ϣ����
	void NumberSort();//��ѧ������
	void ScoreSort();//���ɼ�����
	void Search();//����ѧ����Ϣ
	void NumberSearch();//��ѧ�Ų���
	void NameSearch();//����������
};

