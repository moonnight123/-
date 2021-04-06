#include <iostream>
#include "student_system_h.cpp"
using namespace std;

int main(){
	int select;
	while (true)
	{
		cout << "1.本科生管理系统" << endl;
		cout << "2.研究生管理系统" << endl;
		cout << "3.退出系统" << endl;
		cin >> select;
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