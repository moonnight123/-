#include <iostream>
#include "student_system_h.cpp"
using namespace std;

int main(){
	int select;
	while (true)
	{
		cout << "1.����������ϵͳ" << endl;
		cout << "2.�о�������ϵͳ" << endl;
		cout << "3.�˳�ϵͳ" << endl;
		cin >> select;
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