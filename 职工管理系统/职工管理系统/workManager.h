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
	int m_isEmpty;

	//��ȡԱ������
	int get_Num();

	//���ļ��ж�ȡ����
	void Init_Arry();

	//Ա�������ָ��
	Work** m_Arry;

	//����Ա��
	void Add_Arry();

	//��ʾͨѶ¼
	void Show_Arry();

	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);

	//ɾ��Ա��
	void Del_Arry();

	//�޸�Ա����Ϣ
	void Mod_Arry();

	//���溯��
	void Save();

	~WorkManager();

};
