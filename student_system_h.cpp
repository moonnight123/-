#include "student_system_t.h"


struct student_information1
{
	string name = " ";
	int sex = 0;
	string clas = " ";
	string specialty = " ";
	long int student_number = 0;
};

struct information1
{
	student_information1 s_i_1[MAX];
	int size = 0;
}infor1;

struct student_score
{
	string name = " ";
	string clas = " ";
	int high_math = 0;
	int english = 0;
	int c_language = 0;
	int sum_score = 0;
	int class_ranking = 0;
	int school_ranking = 0;
	long int student_number = 0;
};

struct score
{
	student_score s_c[MAX];
	int size = 0;
}scor;

int ben_student_system()
{
	int select1, select2;

	while (true)
	{
		cout << "1.本科生信息管理系统" << endl;
		cout << "2.本科生成绩管理系统" << endl;
		cout << "3.将信息成绩输入表格" << endl;
		cout << "4.退出学生管理系统" << endl;
		cin >> select1;
		system("cls");

		if (select1 == 1)
		{
			while (true)
			{
				cout << "1.学生基本信息输入 " << endl;
				cout << "2.学生基本信息修改 " << endl;
				cout << "3.删除学生基本资料 " << endl;
				cout << "4.查询学生基本资料 " << endl;
				cout << "5.输出学生基本资料 " << endl;
				cout << "6.退出信息管理系统 " << endl;
				cin >> select2;
				system("cls");
				if (select2 == 6)
				{
					break;
				}
				switch (select2)
				{
				case 1:
					input_information1(&infor1);
					//输入学生信息
					break;
				case 2:
					//学生基本信息修改
					break;
				case 3:
					//删除学生基本资料
					break;
				case 4:
					//查询学生基本资料
					break;
				case 5:
					//输出学生基本资料
					break;
				}
			}
		}

		else if (select1 == 2)
		{
			while (true)
			{
				cout << "  1.学生成绩输入 " << endl;
				cout << "  2.学生成绩计算 " << endl;
				cout << "  3.学生成绩修改 " << endl;
				cout << "  4.学生成绩删除 " << endl;
				cout << "  5.学生成绩查询 " << endl;
				cout << "  6.学生成绩输出 " << endl;
				cout << "7.退出成绩管理系统 " << endl;
				cin >> select2;
				system("cls");
				if (select2 == 7)
				{
					break;
				}
				switch (select2)
				{
				case 1:
					//学生成绩输入
					break;
				case 2:
					//学生成绩计算
					break;
				case 3:
				{
					//学生成绩修改
					break;
				}
				case 4:
					//学生成绩删除
					break;
				case 5:
					//学生成绩查询
					break;
				case 6:
					//学生成绩输出
					break;
				}
			}
		}

		else if (select1 == 3)
		{
			//文件传输至excl表中
		}


		else if (select1 == 4)
		{
			//退出本科生系统
			system("pause");
			return 0;
		}
	}

}

void input_information1(information1* infor1)
{
	cout << "请输入姓名:" << endl;
	string name;
	cin >> name;
	infor1->s_i_1[infor1->size].name = name;

	cout << "请输入性别:" << endl;
	cout << "1-男" << endl;
	cout << "2-女" << endl;
	int sex;
	cin >> sex;
	infor1->s_i_1[infor1->size].sex = sex;

	cout << "请输入班级:" << endl;
	string clas;
	cin >> clas;
	infor1->s_i_1[infor1->size].clas = clas;

	cout << "请输入专业:" << endl;
	string specialty;
	cin >> specialty;
	infor1->s_i_1[infor1->size].specialty = specialty;

	long int student_number;
	student_number = rand() % 10000 + 20200000;
	infor1->s_i_1[infor1->size].student_number = student_number;

	infor1->size++;

	system("cls");
}

