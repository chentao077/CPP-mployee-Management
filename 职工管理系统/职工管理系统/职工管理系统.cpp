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
			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}