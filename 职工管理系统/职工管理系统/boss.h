#pragma once
#include<string>
#include<iostream>
#include"work.h"
using namespace std;

class Boss :public Work
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string getDeptName();
	//���캯��
	Boss(int id, string name, int did);
};