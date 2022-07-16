#pragma once
#include<string>
#include<iostream>
using namespace std;

class Work
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	string m_Name;
	int m_Id;
	int m_DeptId;
};
