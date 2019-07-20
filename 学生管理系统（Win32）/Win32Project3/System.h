#pragma once
#include<string>
class Student
{
	std::string name;
	long number;
	int score;
public:
	Student(){};
	Student(std::string m_name, long m_number, int m_score);
	void set_student(std::string m_name, long m_number, int m_score);
	std::string get_name();
	long get_number();
	int get_score();
};
class System
{
	Student *student;
	int Length;
public:
	System();
	~System();
	void Add(std::string name, long number, int score);//���ѧ��
	void System::Delete(int num);//ɾ��ѧ��
	void Modify(int num, std::string name, long number, int score);//�޸�ѧ����Ϣ
	void Sort(int means);//��ѧ����Ϣ����
	Student Search(long num);//��ѧ�Ų���ѧ����Ϣ
	Student	Search(std::string s);//����������ѧ����Ϣ
};

