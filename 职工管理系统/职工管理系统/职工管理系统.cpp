#include"workManager.h"

int main()
{
	WorkManager vm;
	int input;
	while (true)
	{
		vm.ShowMenu();
		cout << "���������ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 0: //�˳�ϵͳ
			vm.exitSystem();
			break;
		case 1: //���ְ��
			vm.Add_Arry();
			break;
		case 2: //��ʾְ��
			vm.Show_Arry();
			break;
		case 3: //ɾ��ְ��
			vm.Del_Arry();
			break;
		case 4: //�޸�ְ��
			vm.Mod_Arry();
			break;
		case 5: //����ְ��
			vm.Find_Arry();
			break;
		case 6: //����ְ��
			vm.Sort_Arry();
			break;
		case 7: //����ļ�
			vm.Clean_Arry();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}