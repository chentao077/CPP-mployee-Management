#pragma once
#include<string>
#include<iostream>
#include"work.h"
using namespace std;

class Employee:public Work
{
public:
	//显示个人信息
	virtual void ShowInfo();
	//获取岗位名称
	virtual string getDeptName();
	//构造函数
	Employee(int id, string name, int did);
};