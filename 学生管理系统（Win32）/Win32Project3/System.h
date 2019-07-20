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
	void Add(std::string name, long number, int score);//添加学生
	void System::Delete(int num);//删除学生
	void Modify(int num, std::string name, long number, int score);//修改学生信息
	void Sort(int means);//给学生信息排序
	Student Search(long num);//按学号查找学生信息
	Student	Search(std::string s);//按姓名查找学生信息
};

