#include "student_system_t.h"
#include "student_system_t2.h"

int main(){
	int select;
	while (true)
	{
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|            1.����������ϵͳ              |" << endl;
		cout << "\t\t\t\t*            2.�о�������ϵͳ              *" << endl;
		cout << "\t\t\t\t|            3.�˳�ϵͳ                    |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
			ben_student_system();
			//����������ϵͳ
			break;
		case 2:
			yan_student_system();
			//�о�������ϵͳ
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