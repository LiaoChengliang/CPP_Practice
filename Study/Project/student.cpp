#include<iostream>
#include<string>
#include"Student.h"
void Student::display()
{
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex"<<sex<<endl;

}

student::student(/* args */)
{
    num=1;
    name="haolo";
    sex='w';
}

student::~student()
{
}
