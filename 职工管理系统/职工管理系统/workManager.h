#pragma once
#include<iostream>
#include"work.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

using namespace std;

class WorkManager
{
public:

	WorkManager();

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void exitSystem();

	//��¼ͨѶ¼�е�����
	int m_Num;
	
	//�ļ��Ƿ�Ϊ�ձ�־
	bool m_isEmpty;

	//��ȡԱ������
	int get_Num();

	//���ļ��ж�ȡ����
	void Init_Arry();

	//Ա�������ָ��
	Work** m_Arry;

	//����ְ��
	void Add_Arry();

	//���溯��
	void Save();

	~WorkManager();

};
