#include "student_system_t.h"
#include "student_system_t2.h"

int main(){
	int select;
	while (true)
	{
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|            1.本科生管理系统              |" << endl;
		cout << "\t\t\t\t*            2.研究生管理系统              *" << endl;
		cout << "\t\t\t\t|            3.退出系统                    |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
			ben_student_system();
			//本科生管理系统
			break;
		case 2:
			yan_student_system();
			//研究生管理系统
			break;
		case 3:
		{
			system("pause");
			return 0;
		}
		}
		system("cls");
	}



	return 0;
}