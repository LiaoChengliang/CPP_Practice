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
	void Operate();//操作提示
	void Add();//添加学生信息
	void Show();//显示所有学生信息
	void Delete();//删除学生
	void Modify();//修改学生信息
	void Sort();//给学生信息排序
	void NumberSort();//按学号排序
	void ScoreSort();//按成绩排序
	void Search();//查找学生信息
	void NumberSearch();//按学号查找
	void NameSearch();//按姓名查找
};

