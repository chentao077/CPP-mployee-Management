#pragma once
#include<string>
#include<iostream>
using namespace std;

class Work
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	string m_Name;
	int m_Id;
	int m_DeptId;
};
