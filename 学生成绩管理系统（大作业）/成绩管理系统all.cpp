#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	
	int select;
	while(true)
	{
		cout<<"1.本科生管理系统"<<endl;
		cout<<"2.研究生管理系统"<<endl; 
		cout<<"3.退出系统"<<endl; 
		cin>>select;
		switch(select)
		{
			case 1:
				system("start 本科生信息成绩管理系统.exe");
				break;
			case 2:
				system("start 研究生信息成绩管理系统.exe");
				break;
			case 3:
				{
					system("pause");
					return 0;
				}
		}
		system("cls");
	}

}
