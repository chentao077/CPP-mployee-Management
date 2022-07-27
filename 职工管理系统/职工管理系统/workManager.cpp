#pragma once
#include"workManager.h"

WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	//1、文件不存在
	if (!ifs.is_open())
	{
		//初始化人数
		this->m_Num = 0;
		//初始化数组指针
		this->m_Num = NULL;
		//初始化文件为空标志
		this->m_isEmpty = -1;
		ifs.close();
		return;
	}

	//2、文件为空
	char ch;
	ifs >> ch;//读取一个字符
	if (ifs.eof())//文件尾标志
	{
		//初始化人数
		this->m_Num = 0;
		//初始化数组指针
		this->m_Num = NULL;
		//初始化文件为空标志
		this->m_isEmpty = -1;
		ifs.close();
		return;
	}
	
	//3、数据存在，读取数据
	int num = this->get_Num();
	this->m_Num = num;
	//根据职工数创建数组
	this->m_Arry = new Work * [this->m_Num];
	this->Init_Arry();
	//修改文件为空标志
	this->m_isEmpty = 1;
	/*for (int i = 0; i < num; i++)
	{
		cout << "职工号： " << this->m_Arry[i]->m_Id
			<< " 职工姓名： " << this->m_Arry[i]->m_Name
			<< " 部门编号： " << this->m_Arry[i]->m_DeptId << endl;
	}*/
}

//展示菜单
void WorkManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//保存功能
void WorkManager::Save()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	for (int i = 0; i < this->m_Num; i++)
	{
		ofs << this->m_Arry[i]->m_Id << " "
			<< this->m_Arry[i]->m_Name << " "
			<< this->m_Arry[i]->m_DeptId << endl;
	}
	ofs.close();
}

//增加职工
void  WorkManager::Add_Arry()
{
	cout << "请输入要添加的员工数量：" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		//记录新人数
		int NewSize = this->m_Num + addNum;

		//开辟新空间
		Work** NewSpace = new Work * [NewSize+4];

		//将原数组内容释放到新数组
		if (this->m_Arry != NULL)
		{
			for (int i = 0; i < this->m_Num;i++)
			{
				NewSpace[i] = this->m_Arry[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int select;
			cout << "请输入第" <<i+1<<"个员工的id" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个员工的职位" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> select;

			Work* work = NULL;
			switch (select)
			{
			case 1://普通员工
				work = new Employee(id, name, 1);
				break;
			case 2:
				work = new Manager(id, name, 2);
				break;
			case 3:
				work = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//添加数据
			NewSpace[this->m_Num + i] = work;
		}
		//释放原来的数组
		delete[]this->m_Arry;

		//指向新数组
		this->m_Arry = NewSpace;

		//更新数量
		this->m_Num = this->m_Num + addNum;
		
		//保存数据
		this->Save();
		cout << "成功添加" << addNum << "名员工" << endl;
		//修改文件为空标志
		this->m_isEmpty = 1;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键继续，清屏
	system("pause");
	system("cls");
}

//获取员工数量
int WorkManager::get_Num()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);

	int id;
	string name;
	int dId;

	int num = 0;//记录人数
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

//从文件中读取数据
void WorkManager::Init_Arry()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	
	int id;
	string name;
	int dId;

	int tmp = 0;//用于计数
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Work* work = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)//普通员工
		{
			work = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			work = new Employee(id, name, dId);
		}
		else//老板
		{
			work = new Employee(id, name, dId);
		}
		//存放在数组中
		this->m_Arry[tmp] = work;
		tmp++;
	}
	ifs.close();
}
//显示通讯录
void WorkManager::Show_Arry()
{
	if (this->m_isEmpty == -1)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0; i < m_Num; i++)
		{
			this->m_Arry[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
int WorkManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Num; i++)
	{
		if (index == this->m_Arry[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除员工
void WorkManager::Del_Arry()
{
	if (this->m_isEmpty == -1)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int tmp;
		cin >> tmp;
		int index = this->IsExist(tmp);
		if (index == -1)
		{
			cout << "删除失败，未找到这个员工" << endl;
		}
		else
		{
			for (int i = index; i < this->m_Num; i++)
			{
				this->m_Arry[i] = this->m_Arry[i + 1];
			}
			this->m_Num--;
			this->Save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改员工信息
void WorkManager::Mod_Arry()
{
	if (this->m_isEmpty == -1)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int tmp;
		cout << "请输入要修改的职工编号" << endl;
		cin >> tmp;
		int index = this->IsExist(tmp);
		if (index == -1)
		{
			cout << "删除失败，未找到这个员工" << endl;
		}
		else
		{
			delete this->m_Arry[index];
			//输入新信息
			int id;
			string name;
			int select;
			cout << "查到： " << index << "号职工，请输入新职工号： " << endl;
			cin >> id;
			cout << "请输入新姓名" << endl;
			cin >> name;
			cout << "请输入新职位" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> select;

			Work* work = NULL;
			switch (select)
			{
			case 1://普通员工
				work = new Employee(id, name, 1);
				break;
			case 2:
				work = new Manager(id, name, 2);
				break;
			case 3:
				work = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//更新到数组中
			this->m_Arry[index] = work;
			cout << "修改成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//退出系统
void WorkManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

WorkManager::~WorkManager()
{
	if (this->m_Arry != NULL)
	{
		delete[]this->m_Arry;
		this->m_Arry = NULL;
	}
}
