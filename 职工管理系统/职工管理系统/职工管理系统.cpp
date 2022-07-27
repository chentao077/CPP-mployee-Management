#include"workManager.h"

int main()
{
	WorkManager vm;
	int input;
	while (true)
	{
		vm.ShowMenu();
		cout << "请输入你的选择：" << endl;
		cin >> input;
		switch (input)
		{
		case 0: //退出系统
			vm.exitSystem();
			break;
		case 1: //添加职工
			vm.Add_Arry();
			break;
		case 2: //显示职工
			vm.Show_Arry();
			break;
		case 3: //删除职工
			vm.Del_Arry();
			break;
		case 4: //修改职工
			vm.Mod_Arry();
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}