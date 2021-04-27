#include "student_system_t.h"


struct student_information1
{
	string name = " ";//姓名
	int sex = 0;//性别
	string clas = " ";//班级
	string specialty = " ";//专业
	long int student_number = 0;//学号
};

struct information1
{
	student_information1 s_i_1[MAX];
	int size = 0;//记录学生个数
}infor1;

struct student_score
{
	string name = " ";//姓名
	string clas = " ";//班级
	int high_math = 0;//高数成绩
	int english = 0;//英语成绩
	int c_language = 0;//c语言成绩
	int sum_score = 0;//总成绩
	int class_ranking = 0;//班级排名
	int school_ranking = 0;//学校排名
	long int student_number = 0;//学号
};

struct score
{
	student_score s_c[MAX];
	int size = 0;//记录学生个数
}scor;

int ben_student_system()
{
	int select1;
	
	ben_putin_file(&infor1, &scor);

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
			ben_student_information_system();//本科生信息管理系统
		}

		else if (select1 == 2)
		{
			ben_student_score_system();
		}

		else if (select1 == 3)
		{
			//文件传输至excl表中
			ben_putout_file();
		}


		else if (select1 == 4)
		{
			//退出本科生系统
			system("pause");
			return 0;
		}
	}
}

void ben_student_information_system()
{
	//本科生信息管理系统
	int select2;
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
			change_information1(&infor1);
			//学生基本信息修改
			break;
		case 3:
			delect_information1(&infor1);
			//删除学生基本资料
			break;
		case 4:
			look_information1(&infor1);
			//查询学生基本资料
			break;
		case 5:
			putout_information1(&infor1);
			//输出学生基本资料
			break;
		}
	}
}

void ben_student_score_system()
{
	int select2;
	string  arr[100];
	string temp[100];
	//本科生成绩管理系统
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
			input_score(&scor, &infor1);
			//学生成绩输入
			break;
		case 2:
			class_management(&scor,arr,temp);
			//学生成绩计算
			break;
		case 3:
		{
			change_score(&scor);
			cout_ranking(&scor);
			//学生成绩修改
			break;
		}
		case 4:
			delect_student(&scor);
			//学生成绩删除
			break;
		case 5:
			look_score(&scor);
			//学生成绩查询
			break;
		case 6:
			putout_score(&scor);
			//学生成绩输出
			break;
		}
	}
}

void ben_putout_file()
{
	ofstream ofs;

	ofs.open("C:\\Users\\pqy18770657781\\Desktop\\vs2019\\student score system\\student score system\\本科生成绩管理系统.xls", ios::out);
	ofs << "学号\t" << "姓名\t" << "性别\t" << "班级\t" << "专业\t" << "高数\t" << "英语\t" << "C语言\t" << "总成绩\t" << "班排名\t" << "校排名\n";
	
	for (int i = 0; i < infor1.size; i++)
	{
		ofs << infor1.s_i_1[i].student_number << "\t"
			<< infor1.s_i_1[i].name << "\t"
			<< (infor1.s_i_1[i].sex == 1 ? "男" : "女") << "\t"
			<< infor1.s_i_1[i].clas << "\t"
			<< infor1.s_i_1[i].specialty << "\t";

		int number = infor1.s_i_1[i].student_number;
		int test = check_number_file(&scor, number);
		if (test == -1)
		{
			ofs << endl;
		}

		else {
			ofs << scor.s_c[test].high_math << "\t"
				<< scor.s_c[test].english << "\t"
				<< scor.s_c[test].c_language << "\t"
				<< scor.s_c[test].sum_score << "\t"
				<< scor.s_c[test].class_ranking << "\t"
				<< scor.s_c[test].school_ranking << "\t"
				<< endl;
		}

	}
	ofs.close();
	cout << "输入成功！" << endl;
	system("pause");
	system("cls");
}

void ben_putin_file(information1* infor1, score* scor)
{
	ifstream ifs;
	ifs.open("C:\\Users\\pqy18770657781\\Desktop\\vs2019\\student score system\\student score system\\本科生成绩管理系统.xls", ios::in);
	char buf[1024] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		ifs >> buf;
	}


	while (ifs >> buf)
	{
		for (int i = 1; i < 12; i++)
		{
			if (i == 1)
			{
				long int student_number = 0;
				student_number = atol(buf);
				infor1->s_i_1[infor1->size].student_number = student_number;
				scor->s_c[scor->size].student_number = student_number;
				ifs >> buf;
			}

			else if (i == 2)
			{
				infor1->s_i_1[infor1->size].name = buf;
				scor->s_c[scor->size].name = buf;
				ifs >> buf;
			}

			else if (i == 3)
			{
				int sex = 0;
				if (buf == (string)"男")
				{
					sex = 1;
				}

				else if(buf == (string)"女")
				{
					sex = 2;
				}

				ifs >> buf;
			}

			else if (i == 4)
			{
				infor1->s_i_1[infor1->size].clas = buf;
				scor->s_c[scor->size].clas = buf;
				ifs >> buf;
			}

			else if (i == 5)
			{
				infor1->s_i_1[infor1->size].specialty = buf;
				ifs >> buf;
			}

			else if (i == 6)
			{
				int high_math = 0;
				high_math = atoi(buf);
				scor->s_c[scor->size].high_math = high_math;
				ifs >> buf;
			}

			else if (i == 7)
			{
				int english = 0;
				english = atoi(buf);
				scor->s_c[scor->size].english = english;
				ifs >> buf;
			}

			else if (i == 8)
			{
				int c_language = 0;
				c_language = atoi(buf);
				scor->s_c[scor->size].c_language = c_language;
				ifs >> buf;
			}

			else if (i == 9)
			{
				int sum_score = 0;
				sum_score = atoi(buf);
				scor->s_c[scor->size].sum_score = sum_score;
				ifs >> buf;
			}

			else if (i == 10)
			{
				int class_ranking = 0;
				class_ranking = atoi(buf);
				scor->s_c[scor->size].class_ranking = class_ranking;
				ifs >> buf;
			}

			else if (i == 11)
			{
				int school_ranking = 0;
				school_ranking = atoi(buf);
				scor->s_c[scor->size].school_ranking = school_ranking;
			}
		}
		infor1->size++;
		scor->size++;
	}
	ifs.close();
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

	//学号的自动生成
	long int student_number;
	student_number = rand() % 10000 + 20200000;
	infor1->s_i_1[infor1->size].student_number = student_number;

	//学生人数加1
	infor1->size++;

	//清屏
	system("cls");
}

void putout_information1(information1* infor1)
{
	//信息输出
	for (int i = 0; i < infor1->size; i++)
	{
		cout << "姓名:" << infor1->s_i_1[i].name << "   "
			<< "性别:" << (infor1->s_i_1[i].sex == 1 ? "男" : "女") << "   "
			<< "班级:" << infor1->s_i_1[i].clas << "   "
			<< "专业:" << infor1->s_i_1[i].specialty << "   "
			<< "学号:" << infor1->s_i_1[i].student_number << endl;
	}

	system("pause");
	system("cls");
}

int check_information1(information1* infor1)
{
	//判断该学生学号是否存在
	cout << "请输入学生学号：" << endl;
	long int student_number;
	cin >> student_number;
	for (int i = 0; i < infor1->size; i++)
	{
		if (infor1->s_i_1[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_information1(information1* infor1)
{
	int test = check_information1(infor1);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		cout << "请输入修改信息：" << endl;
		cout << "1.姓名" << endl;
		cout << "2.性别" << endl;
		cout << "3.班级" << endl;
		cout << "4.专业" << endl;

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "请输入姓名:" << endl;
			string name;
			cin >> name;
			infor1->s_i_1[test].name = name;
			break;
		}
		case 2:
		{
			cout << "请输入性别:" << endl;
			cout << "1-男" << endl;
			cout << "2-女" << endl;
			int sex;
			cin >> sex;
			infor1->s_i_1[test].sex = sex;
			break;
		}
		case 3:
		{
			cout << "请输入班级:" << endl;
			string clas;
			cin >> clas;
			infor1->s_i_1[test].clas = clas;
			break;
		}
		case 4:
		{
			cout << "请输入专业:" << endl;
			string specialty;
			cin >> specialty;
			infor1->s_i_1[test].specialty = specialty;
			break;
		}
		}
		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}

void delect_information1(information1* infor1)
{
	int test = check_information1(infor1);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		//删除学生信息
		for (int i = test; i < infor1->size + 1; i++)
		{
			//通过将后一位学生的信息覆盖前一位学生的信息的方法实现学生信息的删除
			infor1->s_i_1[i] = infor1->s_i_1[i + 1];
		}
		infor1->size--;//学生人数减1
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void look_information1(information1* infor1)
{
	int test = check_information1(infor1);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		//个人信息输出
		cout << "姓名:" << infor1->s_i_1[test].name << "   "
			<< "性别:" << (infor1->s_i_1[test].sex == 1 ? "男" : "女") << "   "
			<< "班级:" << infor1->s_i_1[test].clas << "   "
			<< "专业:" << infor1->s_i_1[test].specialty << "   "
			<< "学号:" << infor1->s_i_1[test].student_number << endl;
	}
	system("pause");
	system("cls");
}

int check_person(score* scor, information1* infor1)
{
	int num = 0;

	for (int i = 0; i < infor1->size; i++)
	{
		//判断学生信息系统中是否存在该学生姓名
		if (scor->s_c[scor->size].name == infor1->s_i_1[i].name)
		{
			scor->s_c[scor->size].student_number = infor1->s_i_1[i].student_number;
			return 1;
			break;
		}

		else {
			num++;
		}
	}

	if (num == infor1->size)
	{
		return -1;
	}

	return 0;
}

void input_score(score* scor, information1* infor1)
{
	cout << "请输入姓名:" << endl;
	string name;
	cin >> name;
	scor->s_c[scor->size].name = name;

	int test = check_person(scor, infor1);

	if (test == -1)
	{
		cout << "学生信息管理系统中查无此人，请检查是否输入正确！" << endl;
	}

	else
	{
		cout << "请输入班级:" << endl;
		string clas;
		cin >> clas;
		scor->s_c[scor->size].clas = clas;


		cout << "高数成绩：" << endl;
		int high_math;
		cin >> high_math;
		scor->s_c[scor->size].high_math = high_math;

		cout << "英语成绩：" << endl;
		int english;
		cin >> english;
		scor->s_c[scor->size].english = english;

		cout << "c语言成绩：" << endl;
		int c_language;
		cin >> c_language;
		scor->s_c[scor->size].c_language = c_language;

		//计算总成绩
		int sum = 0;
		if (high_math != -1 && english != -1 && c_language != -1)
		{
			sum = scor->s_c[scor->size].high_math + scor->s_c[scor->size].english + scor->s_c[scor->size].c_language;
		}
		scor->s_c[scor->size].sum_score = sum;

		scor->size++;

		cout_ranking(scor);//计算排名
	}
	system("pause");
	system("cls");
}

void cout_ranking(score* scor)
{
	for (int i = 0; i < scor->size; i++)
	{
		for (int j = 0; j < scor->size; j++)
		{
			//通过冒泡排序对学生总成绩进行排名
			if (scor->s_c[j].sum_score < scor->s_c[j + 1].sum_score)
			{
				//对比总成绩，互换学生的结构体次序
				struct student_score temp = scor->s_c[j];
				scor->s_c[j] = scor->s_c[j + 1];
				scor->s_c[j + 1] = temp;
			}
		}
	}

	for (int k = 0; k < scor->size; k++)
	{
		//排名输出
		scor->s_c[k].school_ranking = k + 1;
	}
}

int check_number(score* scor)
{
	//查询本科生信息系统中是否存在该学生学号
	cout << "请输入学生学号：" << endl;
	long int student_number;
	cin >> student_number;
	for (int i = 0; i < scor->size; i++)
	{
		if (scor->s_c[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_score(score* scor)
{
	int test = check_number(scor);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		while (true)
		{
			cout << "请输入修改信息：" << endl;
			cout << "1.姓名" << endl;
			cout << "2.班级" << endl;
			cout << "3.高数成绩" << endl;
			cout << "4.英语成绩" << endl;
			cout << "5.c语言成绩" << endl;
			cout << "6.退出修改" << endl;

			int select;
			cin >> select;
			if (select == 6)
			{
				break;
			}

			else
			{
				switch (select)
				{
				case 1:
				{
					cout << "请输入姓名:" << endl;
					string name;
					cin >> name;
					scor->s_c[test].name = name;
					break;
				}
				case 2:
				{
					cout << "请输入班级:" << endl;
					string clas;
					cin >> clas;
					scor->s_c[test].clas = clas;
					break;
				}
				case 3:
				{
					cout << "高数成绩：" << endl;
					int high_math;
					cin >> high_math;
					scor->s_c[test].high_math = high_math;
					break;
				}
				case 4:
				{
					cout << "英语成绩：" << endl;
					int english;
					cin >> english;
					scor->s_c[test].english = english;
					break;
				}
				case 5:
				{
					cout << "c语言成绩：" << endl;
					int c_language;
					cin >> c_language;
					scor->s_c[test].c_language = c_language;
				}
				}
				system("cls");
			}
		}
		cout << "修改成功" << endl;
		int sum = 0;
		
		if (scor->s_c[test].high_math != -1 && scor->s_c[test].english != -1 && scor->s_c[test].c_language != -1)
		{
			sum = scor->s_c[test].high_math + scor->s_c[test].english + scor->s_c[test].c_language;
		}
		scor->s_c[test].sum_score = sum;

		cout_ranking(scor);
	}
	system("pause");
	system("cls");
}

void delect_student(score* scor)
{
	int test = check_number(scor);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		//通过将后一位学生的信息成绩前一位学生的信息的方法实现学生成绩的删除
		for (int i = test; i < scor->size + 1; i++)
		{
			scor->s_c[i] = scor->s_c[i + 1];
		}
		scor->size--;
		cout << "删除成功" << endl;
	}
	cout_ranking(scor);
	system("pause");
	system("cls");
}

void look_score(score* scor)
{
	int test = check_number(scor);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else {
		cout << "姓名:" << scor->s_c[test].name << "   "
			<< "学号:" << scor->s_c[test].student_number << "   "
			<< "班级:" << scor->s_c[test].clas << "   "
			<< "高数:" << scor->s_c[test].high_math << "   "
			<< "英语:" << scor->s_c[test].english << "   "
			<< "c语言:" << scor->s_c[test].c_language << "   "
			<< "总成绩" << scor->s_c[test].sum_score << "   "
			<< "校排名:" << scor->s_c[test].school_ranking << endl;
	}
	system("pause");
	system("cls");
}

void putout_score(score* scor)
{
	for (int i = 0; i < scor->size; i++)
	{
		cout << "姓名:" << scor->s_c[i].name << "   "
			<< "学号:" << scor->s_c[i].student_number << "   "
			<< "班级:" << scor->s_c[i].clas << "   "
			<< "高数:" << scor->s_c[i].high_math << "   "
			<< "英语:" << scor->s_c[i].english << "   "
			<< "c语言:" << scor->s_c[i].c_language << "   "
			<< "总成绩" << scor->s_c[i].sum_score << "   "
			<< "班排名" << scor->s_c[i].class_ranking << "   "
			<< "校排名:" << scor->s_c[i].school_ranking << endl;
	}
	system("pause");
	system("cls");
}

void class_management(score* scor, string* arr, string *temp)
{
	//先将每个学生的班级输入到一个数组中再进行查重去除重复的班级
	for (int i = 0; i < scor->size; i++)
	{
		arr[i] = scor->s_c[i].clas;
	}

	int m = 0;
	for (int j = 0; j < 100; j++)
	{
		int k = 0;
		for (; k < m; k++)
		{
			if (arr[j] == temp[k])
			{
				break;
			}
		}

		if (k == m)
		{
			temp[m] = arr[j];
			m++;
		}
	}

//遍历已经排好总成绩的学生，将每个学生分到对应的班级中，根据每个学生进入班级的次序对其进行排名
	//i代表数组中的班级序号，从结构体中遍历学生所属的班级与序号为i的班级进行对比
	for (int i = 0; i < 100; i++)
	{
		int k = 0;
		//j代表班级中的排名，从结构体中选中符合i代表的班级的学生，从第一名开始进行排名
		for (int j = 0; j < 100; j++)
		{
			//k代表结构体中学生的序号，从结构体中寻找符合上述条件的学生，如果从第k序号找到，为其赋予排名，再从k+1序号继续寻找，直到遍历完所有学生
			for (; k < scor->size; k++)
			{
				//班级名不能的是空的
				if (scor->s_c[k].clas != " ")
				{
					//遍历的学生班级要与班级数组中第i个班级的名称一致
					if (scor->s_c[k].clas == temp[i])
					{
						scor->s_c[k].class_ranking = j + 1;
						k = k + 1;
						break;
					}
				}
			}
		}
	}
	cout << "计算完成" << endl;
	system("pause");
	system("cls");
}

int check_number_file(score* scor, int number)
{
	for (int i = 0; i < scor->size; i++)
	{
		if (scor->s_c[i].student_number == number)
		{
			return i;
		}
	}
	return -1;
}

void statistics(string* temp, score* scor)
{
	
}    