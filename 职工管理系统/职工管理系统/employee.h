#pragma once
#include<string>
#include<iostream>
#include"work.h"
using namespace std;

class Employee:public Work
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string getDeptName();
	//���캯��
	Employee(int id, string name, int did);
};