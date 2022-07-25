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

	//展示菜单
	void ShowMenu();

	//退出系统
	void exitSystem();

	//记录通讯录中的人数
	int m_Num;
	
	//文件是否为空标志
	bool m_isEmpty;

	//获取员工数量
	int get_Num();

	//从文件中读取数据
	void Init_Arry();

	//员工数组的指针
	Work** m_Arry;

	//增加职工
	void Add_Arry();

	//保存函数
	void Save();

	~WorkManager();

};
