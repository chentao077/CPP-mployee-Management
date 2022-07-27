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
		this->m_isEmpty = -1;
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
		this->m_isEmpty = -1;
		ifs.close();
		return;
	}
	
	//3�����ݴ��ڣ���ȡ����
	int num = this->get_Num();
	this->m_Num = num;
	//����ְ������������
	this->m_Arry = new Work * [this->m_Num];
	this->Init_Arry();
	//�޸��ļ�Ϊ�ձ�־
	this->m_isEmpty = 1;
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
		Work** NewSpace = new Work * [NewSize+4];

		//��ԭ���������ͷŵ�������
		if (this->m_Arry != NULL)
		{
			for (int i = 0; i < this->m_Num;i++)
			{
				NewSpace[i] = this->m_Arry[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int select;
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
		}
		//�ͷ�ԭ��������
		delete[]this->m_Arry;

		//ָ��������
		this->m_Arry = NewSpace;

		//��������
		this->m_Num = this->m_Num + addNum;
		
		//��������
		this->Save();
		cout << "�ɹ����" << addNum << "��Ա��" << endl;
		//�޸��ļ�Ϊ�ձ�־
		this->m_isEmpty = 1;
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
//��ʾͨѶ¼
void WorkManager::Show_Arry()
{
	if (this->m_isEmpty == -1)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
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

//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
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

//ɾ��Ա��
void WorkManager::Del_Arry()
{
	if (this->m_isEmpty == -1)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ�����" << endl;
		int tmp;
		cin >> tmp;
		int index = this->IsExist(tmp);
		if (index == -1)
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ����Ա��" << endl;
		}
		else
		{
			for (int i = index; i < this->m_Num; i++)
			{
				this->m_Arry[i] = this->m_Arry[i + 1];
			}
			this->m_Num--;
			this->Save(); //ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�Ա����Ϣ
void WorkManager::Mod_Arry()
{
	if (this->m_isEmpty == -1)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int tmp;
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		cin >> tmp;
		int index = this->IsExist(tmp);
		if (index == -1)
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ����Ա��" << endl;
		}
		else
		{
			delete this->m_Arry[index];
			//��������Ϣ
			int id;
			string name;
			int select;
			cout << "�鵽�� " << index << "��ְ������������ְ���ţ� " << endl;
			cin >> id;
			cout << "������������" << endl;
			cin >> name;
			cout << "��������ְλ" << endl;
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

			//���µ�������
			this->m_Arry[index] = work;
			cout << "�޸ĳɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
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
