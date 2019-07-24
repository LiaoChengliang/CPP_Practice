#include<iostream>
#include<string>
#include"student.h"
void student::display()
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
