#include "student_system_t2.h"

struct student_information2
{
	string name = " ";
	int sex = 0;
	string clas = " ";
	string specialty = " ";
	string research_direction = " ";
	string tutor = " ";
	long int student_number = 0;
};

struct information2
{
	student_information2 s_i_2[MAX];
	int size = 0;
}infor2;

struct student_score2
{
	string name = " ";
	string clas = " ";
	int all_class_score = 0;
	int thesis = 0;
	int sum_score = 0;
	int class_ranking = 0;
	int school_ranking = 0;
	long int student_number = 0;
};

struct score2
{
	student_score2 s_c_2[MAX];
	int size = 0;
}scor2;

int yan_student_system()
{
	int select1, select2;

	while (true)
	{
		cout << "1.研究生信息管理系统" << endl;
		cout << "2.研究生成绩管理系统" << endl;
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
					input_information2(&infor2);
					//学生基本信息输入
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
			//退出研究生系统
			system("pause");
			return 0;
		}
	}
}

void input_information2(information2* infor2)
{
	cout << "请输入姓名:" << endl;
	string name;
	cin >> name;
	infor2->s_i_2[infor2->size].name = name;

	cout << "请输入性别:" << endl;
	cout << "1-男" << endl;
	cout << "2-女" << endl;
	int sex;
	cin >> sex;
	infor2->s_i_2[infor2->size].sex = sex;

	cout << "请输入班级:" << endl;
	string clas;
	cin >> clas;
	infor2->s_i_2[infor2->size].clas = clas;

	cout << "请输入专业:" << endl;
	string specialty;
	cin >> specialty;
	infor2->s_i_2[infor2->size].specialty = specialty;

	cout << "请输入研究方向：" << endl;
	string research_direction;
	cin >> research_direction;
	infor2->s_i_2[infor2->size].research_direction = research_direction;

	cout << "请输入导师姓名：" << endl;
	string tutor;
	cin >> tutor;
	infor2->s_i_2[infor2->size].tutor = tutor;

	long int student_number;
	student_number = rand() % 10000 + 20190000;
	infor2->s_i_2[infor2->size].student_number = student_number;

	infor2->size++;

	system("cls");
}
