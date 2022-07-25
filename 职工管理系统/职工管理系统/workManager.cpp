#pragma once
#include"workManager.h"

WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	//1���ļ�������
	if (!ifs.is_open())
	{
		//��ʼ������
		this->m_Num = 0;
		//��ʼ������ָ��
		this->m_Num = NULL;
		//��ʼ���ļ�Ϊ�ձ�־
		this->m_isEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ�Ϊ��
	char ch;
	ifs >> ch;//��ȡһ���ַ�
	if (ifs.eof())//�ļ�β��־
	{
		//��ʼ������
		this->m_Num = 0;
		//��ʼ������ָ��
		this->m_Num = NULL;
		//��ʼ���ļ�Ϊ�ձ�־
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	
	//3�����ݴ��ڣ���ȡ����
	int num = this->get_Num();
	this->m_Num = num;
	//����ְ������������
	this->m_Arry = new Work * [this->m_Num];
	this->Init_Arry();
	/*for (int i = 0; i < num; i++)
	{
		cout << "ְ���ţ� " << this->m_Arry[i]->m_Id
			<< " ְ�������� " << this->m_Arry[i]->m_Name
			<< " ���ű�ţ� " << this->m_Arry[i]->m_DeptId << endl;
	}*/
}

//չʾ�˵�
void WorkManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//���湦��
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

//����ְ��
void  WorkManager::Add_Arry()
{
	cout << "������Ҫ��ӵ�Ա��������" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		//��¼������
		int NewSize = this->m_Num + addNum;

		//�����¿ռ�
		Work** NewSpace = new Work * [NewSize];

		//��ԭ���������ͷŵ�������
		if (this->m_Arry != NULL)
		{
			for (int i = 0; i < this->m_Num;i++)
			{
				NewSpace[i] = this->m_Arry[i];
			}
		}

		//����������
		int id;
		string name;
		int select;
		for (int i = 0; i < addNum; i++)
		{
			cout << "�������" <<i+1<<"��Ա����id" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "��Ա����ְλ" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> select;

			Work* work = NULL;
			switch (select)
			{
			case 1://��ͨԱ��
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

			//�������
			NewSpace[this->m_Num + i] = work;

			//�ͷ�ԭ��������
			delete[]this->m_Arry;

			//ָ��������
			this->m_Arry = NewSpace;

			//��������
			this->m_Num = this->m_Num + addNum;

			//��������
			this->Save();
			cout << "��ӳɹ�" << endl;
		}
	}
	else
	{
		cout << "��������" << endl;
	}
	//�����������������
	system("pause");
	system("cls");
}

//��ȡԱ������
int WorkManager::get_Num()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);

	int id;
	string name;
	int dId;

	int num = 0;//��¼����
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

//���ļ��ж�ȡ����
void WorkManager::Init_Arry()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	
	int id;
	string name;
	int dId;

	int tmp = 0;//���ڼ���
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Work* work = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)//��ͨԱ��
		{
			work = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			work = new Employee(id, name, dId);
		}
		else//�ϰ�
		{
			work = new Employee(id, name, dId);
		}
		//�����������
		this->m_Arry[tmp] = work;
		tmp++;
	}
	ifs.close();
}

//�˳�ϵͳ
void WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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
