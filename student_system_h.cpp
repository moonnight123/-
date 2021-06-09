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

struct one_class0
{
	string clas = " ";
	int high_math_sum = 0;
	int english_sum = 0;
	int c_language_sum = 0;
	double high_math_ave = 0;
	double english_ave = 0;
	double c_language_ave = 0;
	int size = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0;
	int a3 = 0, b3 = 0, c3 = 0, d3 = 0, e3 = 0;
};

struct all_class0
{
	one_class0 o_c_0[MAX];
	int size = 0;
}a_c_0;

int ben_student_system()
{
	int select1;
	
	ben_putin_file(&infor1, &scor);

	while (true)
	{
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|            1.本科生信息管理系统          |" << endl;
		cout << "\t\t\t\t|            2.本科生成绩管理系统          |" << endl;
		cout << "\t\t\t\t|            3.将信息成绩输入表格          |" << endl;
		cout << "\t\t\t\t|             4.退出学生管理系统           |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
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
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|            1.学生基本信息输入            |" << endl;
		cout << "\t\t\t\t|            2.学生基本信息修改            |" << endl;
		cout << "\t\t\t\t|            3.删除学生基本资料            |" << endl;
		cout << "\t\t\t\t|            4.查询学生基本资料            |" << endl;
		cout << "\t\t\t\t|            5.输出学生基本资料            |" << endl;
		cout << "\t\t\t\t|            6.退出信息管理系统            |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
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
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|              1.学生成绩输入              |" << endl;
		cout << "\t\t\t\t|              2.学生成绩计算              |" << endl;
		cout << "\t\t\t\t*              3.学生成绩修改              *" << endl;
		cout << "\t\t\t\t|              4.学生成绩删除              |" << endl;
		cout << "\t\t\t\t|              5.学生成绩查询              |" << endl;
		cout << "\t\t\t\t*              6.学生成绩输出              *" << endl;
		cout << "\t\t\t\t|            7.学生成绩统计输出            |" << endl;
		cout << "\t\t\t\t|            8.退出成绩管理系统            |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cin >> select2;
		system("cls");
		if (select2 == 8)
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
			class_management(&scor,arr,temp,&a_c_0);
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

		case 7:
			cout_class(&a_c_0);
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

				infor1->s_i_1[infor1->size].sex = sex;
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

	while (true)
	{
		cin >> name;

		if (typeid(name) == typeid(string))
		{
			break;
		}

		else
		{
			cout << "请重新输入\r";
		}

	}
	
	infor1->s_i_1[infor1->size].name = name;

	cout << "请输入性别:" << endl;
	cout << "1-男" << endl;
	cout << "2-女" << endl;
	int sex;
	
	while (true)
	{
		cin >> sex;
		if (typeid(sex) == typeid(int))
		{
			break;
		}

		else
		{
			cout << "请重新输入" << endl;
		}
	}
	infor1->s_i_1[infor1->size].sex = sex;

	cout << "请输入班级:" << endl;
	string clas;
	
	while (true)
	{
		cin >> clas;
		if (typeid(clas) == typeid(string))
		{
			break;
		}

		else
		{
			cout << "请重新输入\r";
		}
	}

	infor1->s_i_1[infor1->size].clas = clas;

	cout << "请输入专业:" << endl;
	string specialty;
	
	while (true)
	{
		cin >> specialty;
		if (typeid(specialty) == typeid(string))
		{
			break;
		}

		else
		{
			cout << "请重新输入\r" ;
		}
	}
	infor1->s_i_1[infor1->size].specialty = specialty;

	//学号的自动生成
	long int student_number;
	student_number = infor1->size + 20200001;
	infor1->s_i_1[infor1->size].student_number = student_number;

	//学生人数加1
	infor1->size++;

	//清屏
	system("cls");
}

void putout_information1(information1* infor1)
{
	//信息输出
	for_information(infor1, 0, 10);
	int num = 0;//页数

	while (true)
	{
		int select = 0;
		cin >> select;
		system("cls");
		
		switch (select)
		{
		case 1:
		{
			//首页
			num = 0;
			for_information(infor1,0,10);
		}
			break;
		case 2:
		{
			//目录
			goto GOBACK;
		}
			break;
		case 3:
		{
			//上一页
			if (num -10< 0)
			{
				cout << "已是首页" << endl;
				system("pause");
				system("cls");
				for_information(infor1, 0, 10);
			}

			else if (num -10>= 0)
			{
				num = num - 10;
				for_information(infor1, num, num + 10);
			}
		}
			break;
		case 4:
			//下一页
			
			if (num + 10 > infor1->size)
			{
				cout << "已是尾页" << endl;
				system("pause");
				system("cls");
				for_information(infor1, num, infor1->size);
			}

			else if (num + 20 > infor1->size)
			{
				num = num + 10;
				for_information(infor1, num, infor1->size);
			}

			else
			{
				num = num + 10;
				for_information(infor1, num, num + 10);
			}
			
			break;
		case 5:
		{
			//尾页
			if (infor1->size % 10 == 0)
			{
				num = infor1->size - 10;
			}

			else if (infor1->size % 10 != 0)
			{
				num = infor1->size - (infor1->size % 10);
			}
			for_information(infor1, num,infor1->size);
		}
			break;
		default:
			break;
		}
	}

GOBACK:
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
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|               请输入修改信息：           |" << endl;
		cout << "\t\t\t\t|                  1.姓名                  |" << endl;
		cout << "\t\t\t\t|                  2.性别                  |" << endl;
		cout << "\t\t\t\t|                  3.班级                  |" << endl;
		cout << "\t\t\t\t|                  4.专业                  |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
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
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	cout << "\t\t\t\t|              1.查询个人信息              |"<< endl;
	cout << "\t\t\t\t|              2.查询班级信息              |" << endl;
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		look_one_information(infor1);
	}
	
	else if (select == 2)
	{
		look_class_information(infor1);
	}
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
			cout << "\t\t\t\t*---------------------*--------------------*" << endl;
			cout << "\t\t\t\t|              请输入修改信息：            |" << endl;
			cout << "\t\t\t\t|                  1.姓名                  |" << endl;
			cout << "\t\t\t\t|                  2.班级                  |" << endl;
			cout << "\t\t\t\t|                3.高数成绩                |" << endl;
			cout << "\t\t\t\t|                4.英语成绩                |" << endl;
			cout << "\t\t\t\t|                5.c语言成绩               |" << endl;
			cout << "\t\t\t\t|                6.退出修改                |" << endl;
			cout << "\t\t\t\t*---------------------*--------------------*" << endl;
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
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	cout << "\t\t\t\t|             1.查询个人成绩               |" << endl;
	cout << "\t\t\t\t|             2.查询班级成绩               |" << endl;
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	int select = 0;
	cin >> select;

	system("cls");
	if (select == 1)
	{
		look_one_score(scor);
	}

	else if(select == 2)
	{
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		cout << "\t\t\t\t|            1.查询班级全体学生成绩        |" << endl;
		cout << "\t\t\t\t|          2.查询班级课程不及格学生信息    |" << endl;
		cout << "\t\t\t\t*---------------------*--------------------*" << endl;
		int choice = 0;
		cin >> choice;

		system("cls");

		if (choice == 1)
		{
			look_class_score(scor);
		}
		
		else if (choice == 2)
		{
			look_the_bad_score_student(scor);
		}

		system("pause");
		system("cls");
	}
}

void putout_score(score* scor)
{
	for_score(scor, 0, 10);
	int num = 0;//页数

	while (true)
	{
		int select = 0;
		cin >> select;
		system("cls");

		switch (select)
		{
		case 1:
		{
			//首页
			num = 0;
			for_score(scor, 0, 10);
		}
		break;
		case 2:
		{
			//目录
			goto GOBACK;
		}
		break;
		case 3:
		{
			//上一页
			if (num - 10 < 0)
			{
				cout << "已是首页" << endl;
				system("pause");
				system("cls");
				for_score(scor, 0, 10);
			}

			else if (num - 10 >= 0)
			{
				num = num - 10;
				for_score(scor, num, num + 10);
			}
		}
		break;
		case 4:
			//下一页

			if (num + 10 > scor->size)
			{
				cout << "已是尾页" << endl;
				system("pause");
				system("cls");
				for_score(scor, num, scor->size);
			}

			else if (num + 20 > scor->size)
			{
				num = num + 10;
				for_score(scor, num, scor->size);
			}

			else
			{
				num = num + 10;
				for_score(scor, num, num + 10);
			}

			break;
		case 5:
		{
			//尾页
			if (scor->size % 10 == 0)
			{
				num = scor->size - 10;
			}

			else if (scor->size % 10 != 0)
			{
				num = scor->size - (scor->size % 10);
			}
			for_score(scor, num, scor->size);
		}
		break;
		default:
			break;
		}
	}

GOBACK:
	system("pause");
	system("cls");
}

void class_management(score* scor, string* arr, string *temp,all_class0 *a_c_0)
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

	for (int n = 0; n < m - 1; n++)
	{
		a_c_0->o_c_0[a_c_0->size].clas = temp[n];
		a_c_0->size++;
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
						a_c_0->o_c_0[i].high_math_sum = a_c_0->o_c_0[i].high_math_sum + scor->s_c[k].high_math;
						a_c_0->o_c_0[i].english_sum = a_c_0->o_c_0[i].english_sum + scor->s_c[k].english;
						a_c_0->o_c_0[i].c_language_sum = a_c_0->o_c_0[i].c_language_sum + scor->s_c[k].c_language;
						scor->s_c[k].class_ranking = j + 1;
						a_c_0->o_c_0[i].size++;
						cout_abc(i, k, scor, a_c_0);
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

void cout_class(all_class0* a_c_0)
{
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	cout << "\t\t\t\t|               1.班级平均成绩             |" << endl;
	cout << "\t\t\t\t|            2.班级课程分数等级统计        |" << endl;
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		cout_ave(a_c_0);
		break;

	case 2:
		print(a_c_0);
		break;

	default:
		break;
	}
}

void cout_ave(all_class0* a_c_0)
{
	for (int i = 0; i < a_c_0->size; i++)
	{
		a_c_0->o_c_0[i].high_math_ave = a_c_0->o_c_0[i].high_math_sum / (a_c_0->o_c_0[i].size * 1.0);
		a_c_0->o_c_0[i].c_language_ave = a_c_0->o_c_0[i].c_language_sum / (a_c_0->o_c_0[i].size * 1.0);
		a_c_0->o_c_0[i].english_ave = a_c_0->o_c_0[i].english_sum / (a_c_0->o_c_0[i].size * 1.0);
	}

	for (int j = 0; j < a_c_0->size; j++)
	{
		cout << "班级：" << a_c_0->o_c_0[j].clas << "   "
			<< "高数平均分:" << a_c_0->o_c_0[j].high_math_ave<< "   "
			<< "英语平均分:" << a_c_0->o_c_0[j].english_ave <<"   "
			<<"c语言平均分"<< a_c_0->o_c_0[j].c_language_ave << "   "
			<< endl;
	}

	system("pause");
	system("cls");
}

void cout_abc(int i, int k, score* scor, all_class0* a_c_0)
{
	int num = 1;
	judje(scor->s_c[k].high_math, num, i, a_c_0);
	num = 2;
	judje(scor->s_c[k].english, num, i, a_c_0);
	num = 3;
	judje(scor->s_c[k].c_language, num, i, a_c_0);
}

void judje(int score, int num, int i, all_class0* a_c_0)
{
	if (score >= 90)
	{
		if (num == 1)
			a_c_0->o_c_0[i].a++;

		else if (num == 2)
			a_c_0->o_c_0[i].a2++;
		else if (num == 3)
			a_c_0->o_c_0[i].a3++;
	}

	else if (score < 90 && score >= 80)
	{
		if (num == 1)
			a_c_0->o_c_0[i].b++;

		else if (num == 2)
			a_c_0->o_c_0[i].b2++;

		else if (num == 3)
			a_c_0->o_c_0[i].b3++;
	}

	else if (score < 80 && score >= 70)
	{
		if (num == 1)
			a_c_0->o_c_0[i].c++;

		else if (num == 2)
			a_c_0->o_c_0[i].c2++;

		else if (num == 3)
			a_c_0->o_c_0[i].c3++;
	}

	else if (score < 70 && score >= 60)
	{
		if (num == 1)
			a_c_0->o_c_0[i].d++;

		else if (num == 2)
			a_c_0->o_c_0[i].d2++;

		else if (num == 3)
			a_c_0->o_c_0[i].d3++;
	}

	else if (score < 60)
	{
		if (num == 1)
			a_c_0->o_c_0[i].e++;

		else if (num == 2)
			a_c_0->o_c_0[i].e2++;

		else if (num == 3)
			a_c_0->o_c_0[i].e3++;
	}
}

void print(all_class0* a_c_0)
{
	cout << "请输入班级名称" << endl;
	string clas;
	cin >> clas;
	int text = check_class(clas, a_c_0);

	system("cls");
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	cout << "\t\t\t\t             请输入要统计的科目:		    " << endl;
	cout << "\t\t\t\t                 1.高数成绩				" << endl;
	cout << "\t\t\t\t                 2.英语成绩				" << endl;
	cout << "\t\t\t\t                 3.c语言成绩               " << endl;
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	int select = 0;
	cin >> select;

	system("cls");

	if (select == 1)
	{
		cout << "优秀:" << a_c_0->o_c_0[text].a << "   "
			<< "良好:" << a_c_0->o_c_0[text].b << "   "
			<< "中等:" << a_c_0->o_c_0[text].c << "   "
			<< "及格:" << a_c_0->o_c_0[text].d << "   "
			<< "不及格:" << a_c_0->o_c_0[text].e << "   "
			<< endl;
	}

	else if (select == 2)
	{
		cout << "优秀:" << a_c_0->o_c_0[text].a2 << "   "
			<< "良好:" << a_c_0->o_c_0[text].b2 << "   "
			<< "中等:" << a_c_0->o_c_0[text].c2 << "   "
			<< "及格:" << a_c_0->o_c_0[text].d2 << "   "
			<< "不及格:" << a_c_0->o_c_0[text].e2 << "   "
			<< endl;
	}

	else if (select == 3)
	{
		cout << "优秀:" << a_c_0->o_c_0[text].a3 << "   "
			<< "良好:" << a_c_0->o_c_0[text].b3 << "   "
			<< "中等:" << a_c_0->o_c_0[text].c3 << "   "
			<< "及格:" << a_c_0->o_c_0[text].d3 << "   "
			<< "不及格:" << a_c_0->o_c_0[text].e3 << "   "
			<< endl;
	}

	system("pause");
	system("cls");
}

int check_class(string clas, all_class0* a_c_0)
{
	for (int i = 0; i < a_c_0->size; i++)
	{
		if (a_c_0->o_c_0[i].clas == clas)
		{
			return i;
		}
	}

	return -1;
}

void for_information(information1* infor1, int i,int j)
{
	for (; i < j; i++)
	{
		cout << "姓名:" << infor1->s_i_1[i].name << "   \t"
			<< "性别:" << (infor1->s_i_1[i].sex == 1 ? "男" : "女") << "   \t"
			<< "班级:" << infor1->s_i_1[i].clas << "   \t"
			<< "专业:" << infor1->s_i_1[i].specialty << "   \t"
			<< "学号:" << infor1->s_i_1[i].student_number << endl;
	}
	cout << "1.首页" <<"   "<< "2.目录" << "   " << "3.上一页" << "   " << "4.下一页" << "   " << "5.尾页" << endl;
}

void for_score(score* scor, int i, int j)
{
	for (; i < j; i++)
	{
		cout << "姓名:" << scor->s_c[i].name << "\t"
			<< "学号:" << scor->s_c[i].student_number << "   "
			<< "班级:" << scor->s_c[i].clas << "\t"
			<< "高数:" << scor->s_c[i].high_math << "\t"
			<< "英语:" << scor->s_c[i].english << "\t"
			<< "c语言:" << scor->s_c[i].c_language << "\t"
			<< "总成绩" << scor->s_c[i].sum_score << "   "
			<< "班排名" << scor->s_c[i].class_ranking << "\t"
			<< "校排名:" << scor->s_c[i].school_ranking << endl;
	}

	cout << "1.首页" << "   " << "2.目录" << "   " << "3.上一页" << "   " << "4.下一页" << "   " << "5.尾页" << endl;
}

void look_one_information(information1* infor1)
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

void look_class_information(information1* infor1)
{
	string clas = " ";
	cout << "请输入班级：";
	cin >> clas;
	int test = 0;
	for (int i = 0; i < infor1->size; i++)
	{
		if (infor1->s_i_1[i].clas == clas)
		{
			cout << "姓名:" << infor1->s_i_1[i].name << "   "
				<< "性别:" << (infor1->s_i_1[i].sex == 1 ? "男" : "女") << "   "
				<< "班级:" << infor1->s_i_1[i].clas << "   "
				<< "专业:" << infor1->s_i_1[i].specialty << "   "
				<< "学号:" << infor1->s_i_1[i].student_number << endl;
			test++;
		}
	}

	if (test == 0)
	{
		cout << "该班级不存在" << endl;
	}

	system("pause");
	system("cls");
}

void look_one_score(score* scor)
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
			<< "班排名" << scor->s_c[test].class_ranking << "   "
			<< "校排名:" << scor->s_c[test].school_ranking << endl;
	}
	system("pause");
	system("cls");
}

void look_class_score(score* scor)
{
	string clas = " ";
	cout << "请输入班级：";
	cin >> clas;
	int test = 0;

	for (int i = 0; i < scor->size; i++)
	{
		if (scor->s_c[i].clas == clas)
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
			test++;
		}
	}

	if (test == 0)
	{
		cout << "该班级不存在" << endl;
	}

	system("pause");
	system("cls");
}

void look_the_bad_score_student(score *scor)
{
	string clas = " ";
	cout << "请输入班级：";
	cin >> clas;
	system("cls");
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	cout << "\t\t\t\t|             请选择课程成绩：             |" << endl;
	cout << "\t\t\t\t|               1.高数成绩                 |" << endl;
	cout << "\t\t\t\t|               2.英语成绩                 |" << endl;
	cout << "\t\t\t\t|               3.c语言成绩                |" << endl;
	cout << "\t\t\t\t*---------------------*--------------------*" << endl;
	int select = 0;
	cin >> select;

	system("cls");

	switch (select)
	{
	case 1:
	{
		for (int i = 0; i < scor->size; i++)
		{
			if(scor->s_c[i].clas == clas)
				look_the_bad_score(scor, i, scor->s_c[i].high_math);
		}
	}
		break;
	case 2:
	{
		for (int i = 0; i < scor->size; i++)
		{
			if(scor->s_c[i].clas == clas)
				look_the_bad_score(scor, i, scor->s_c[i].english);
		}
	}
		break;
	case 3:
	{
		for (int i = 0; i < scor->size; i++)
		{
			if(scor->s_c[i].clas == clas)
				look_the_bad_score(scor, i, scor->s_c[i].c_language);
		}
	}
		break;
	default:
		break;
	}
}

void look_the_bad_score(score* scor,int i,int score)
{
		if (score < 60)
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
}
