#include "MSystem.h"
#include<iostream>
#include<string>
System::System()//构造函数
{
	Length = 0;
}
void System::Operate()
{
	std::cout << "------------请选择以下操作-------------" << std::endl;
	std::cout << "------------1.添加学生-----------------" << std::endl;
	std::cout << "------------2.显示所有学生信息---------" << std::endl;
	std::cout << "------------3.删除---------------------" << std::endl;
	std::cout << "------------4.修改---------------------" << std::endl;
	std::cout << "------------5.排序---------------------" << std::endl;
	std::cout << "------------6.查找---------------------" << std::endl;
	std::cout << "------------7.退出系统-----------------" << std::endl;
	std::cout << "请输入操作";
}
void System::Add()//添加学生
{
	std::cout << "添加学生数量：";
	int num;
	std::cin >> num;
	for (int i = Length; i <Length + num; i++)
	{
		std::cout << "输入第" << i + 1 << "个学生姓名：";
		std::cin >> student[i].name;
		std::cout << "学号：";
		std::cin >> student[i].number;
		std::cout << "成绩：";
		std::cin >> student[i].score;
	}
	Length = Length + num;
}
void System::Show()//显示所有信息
{
	for (int i = 0; i < Length; i++)
	{
		std::cout << i + 1 << ".姓名:" << student[i].name << "	学号:" << student[i].number << "	成绩:" << student[i].score << std::endl;
	}
}
void System::Delete()//删除学生
{
	std::cout << "需要删除第几个学生：";
	int num;
	std::cin >> num;
	for (int i = num - 1; i < Length - 1; i++)
	{
		student[i] = student[i + 1];
	}
	if (Length> 0)
	{
		Length = Length - 1;
		std::cout << "已删除！" << std::endl;
	}

}
void System::Modify()//修改学生信息
{
	std::cout << "需要修改第几个学生信息：";
	int num;
	std::cin >> num;
	std::cout << "输入第" << num << "个学生姓名：";
	std::cin >> student[num - 1].name;
	std::cout << "学号：";
	std::cin >> student[num - 1].number;
	std::cout << "成绩：";
	std::cin >> student[num - 1].score;
	std::cout << "已修改！";
}
void System::Sort()//排序
{
	std::cout << "1.按学号排序  2.按成绩排序" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1:NumberSort(); break;
	case 2:ScoreSort(); break;
	}
	std::cout << "排序完成\n";
}
void System::Search()//查找
{
	std::cout << "1.按学号查找   2.按姓名查找" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1:NumberSearch(); break;
	case 2:NameSearch(); break;
	}
}
void System::NumberSort()//按学号排序
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
void System::ScoreSort()//按成绩排序
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
void System::NumberSearch()//按学号查找
{
	std::cout << "请输入学号：";
	double num;
	std::cin >> num;
	for (int i = 0; i < Length; i++)
	{
		if (student[i].number == num)
		{
			std::cout << "姓名:" << student[i].name << "	学号:" << student[i].number << "	成绩:" << student[i].score << std::endl;
			return;
		}
	}
	std::cout << "查找失败!" << std::endl;
}
void System::NameSearch()//按姓名查找
{
	std::cout << "请输入姓名：";
	std::string s;
	std::cin >> s;
	for (int i = 0; i <Length; i++)
	{
		if (student[i].name == s)
		{
			std::cout << "姓名:" << student[i].name << "	学号:" << student[i].number << "	成绩:" << student[i].score << std::endl;
			return;
		}
	}
	std::cout << "查找失败!" << std::endl;
}