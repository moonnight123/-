#include "student_system_t2.h"

struct student_information2
{
	string name = " ";//姓名
	int sex = 0;;//性别
	string clas = " ";//班级
	string specialty = " ";//专业
	string research_direction = " ";//研究方向
	string tutor = " ";//导师
	long int student_number = 0;//学号
};

struct information2
{
	student_information2 s_i_2[MAX];
	int size = 0;//记录学生个数
}infor2;

struct student_score2
{
	string name = " ";//姓名
	string clas = " ";//班级
	int all_class_score = 0;//课程总成绩
	int thesis = 0;//论文成绩
	int sum_score = 0;//总成绩
	int class_ranking = 0;//班级排名
	int school_ranking = 0;//学校排名
	long int student_number = 0;//学号
};

struct score2
{
	student_score2 s_c_2[MAX];
	int size = 0;
}scor2;

struct one_class
{
	string clas = " ";
	int all_class_score_sum = 0;
	int thesis_sum = 0;
	double all_class_ave = 0;
	double thesic_ave = 0;
	int size = 0;
	int a = 0, b = 0, c= 0, d = 0, e = 0;
	int a2=0, b2=0, c2=0, d2=0, e2 = 0;
};

struct all_class
{
	one_class o_c[MAX];
	int size = 0;
}a_c;

int yan_student_system()
{
	int select1;

	yan_putin_file(&infor2, &scor2);

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
			yan_student_information_system();//研究生信息管理系统
		}

		else if (select1 == 2)
		{
			yan_student_score_system();//研究生成绩管理系统
		}

		else if (select1 == 3)
		{
			yan_putout_file();
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

void yan_student_information_system()
{
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
			input_information2(&infor2);
			//学生基本信息输入
			break;
		case 2:
			change_information2(&infor2);
			//学生基本信息修改
			break;
		case 3:
			delect_information2(&infor2);
			//删除学生基本资料
			break;
		case 4:
			look_information2(&infor2);
			//查询学生基本资料
			break;
		case 5:
			putout_information2(&infor2);
			//输出学生基本资料
			break;
		}
	}
}

void yan_student_score_system()
{
	int select2;
	string  arr[100];

	while (true)
	{
		cout << "  1.学生成绩输入 " << endl;
		cout << "  2.学生成绩计算和统计 " << endl;
		cout << "  3.学生成绩修改 " << endl;
		cout << "  4.学生成绩删除 " << endl;
		cout << "  5.学生成绩查询 " << endl;
		cout << "  6.学生成绩输出 " << endl;
		cout << "7.学生成绩统计输出" << endl;
		cout << "8.退出成绩管理系统 " << endl;
		cin >> select2;
		system("cls");
		if (select2 == 8)
		{
			break;
		}
		switch (select2)
		{
		case 1:
			input_score(&scor2, &infor2);
			//学生成绩输入
			break;
		case 2:
			class_management(&scor2, arr,&a_c);
			//学生成绩计算
			break;
		case 3:
		{
			change_score(&scor2);
			//学生成绩修改
			break;
		}
		case 4:
			delect_student(&scor2);
			//学生成绩删除
			break;
		case 5:
			look_score(&scor2);
			//学生成绩查询
			break;
		case 6:
			putout_score(&scor2);
			//学生成绩输出
			break;
		case 7:
			cout_class(&a_c);
			break;
		}
	}
}

void yan_putout_file()
{
	ofstream ofs;
	ofs.open("C:\\Users\\pqy18770657781\\Desktop\\vs2019\\student score system\\student score system\\研究生成绩管理系统.xls", ios::out);
	ofs << "学号\t" << "姓名\t" << "性别\t" << "班级\t" << "专业\t" << "研究方向\t" << "导师\t" << "课程总成绩\t" << "论文成绩\t" << "总成绩\t" << "班排名\t" << "校排名\n";
	for (int i = 0; i < infor2.size; i++)
	{
		ofs << infor2.s_i_2[i].student_number << "\t"
			<< infor2.s_i_2[i].name << "\t"
			<< (infor2.s_i_2[i].sex == 1 ? "男" : "女") << "\t"
			<< infor2.s_i_2[i].clas << "\t"
			<< infor2.s_i_2[i].specialty << "\t"
			<< infor2.s_i_2[i].research_direction << "\t"
			<< infor2.s_i_2[i].tutor << "\t";

		int number = infor2.s_i_2[i].student_number;
		int test = check_number_file(&scor2, number);
		if (test == -1)
		{
			ofs << endl;
		}

		else {
			ofs<< scor2.s_c_2[test].all_class_score << "\t"
			<< scor2.s_c_2[test].thesis << "\t"
			<< scor2.s_c_2[test].sum_score << "\t"
			<< scor2.s_c_2[test].class_ranking << "\t"
			<< scor2.s_c_2[test].school_ranking << "\t"
			<< endl;
		}
		  
	}
	ofs.close();
	cout << "输入成功！" << endl;
	system("pause");
	system("cls");
}

void yan_putin_file(information2* infor2, score2* scor2)
{
	ifstream ifs;
	ifs.open("C:\\Users\\pqy18770657781\\Desktop\\vs2019\\student score system\\student score system\\研究生成绩管理系统.xls", ios::in);
	char buf[1024] = { 0 };
	for (int i = 0; i < 12; i++)
	{
		ifs >> buf;
	}


	while (ifs >> buf)
	{
		for (int i = 1; i < 13; i++)
		{
			if (i == 1)
			{
				long int student_number = 0;
				student_number = atol(buf);
				infor2->s_i_2[infor2->size].student_number = student_number;
				scor2->s_c_2[scor2->size].student_number = student_number;
				ifs >> buf;
			}

			else if (i == 2)
			{
				infor2->s_i_2[infor2->size].name = buf;
				scor2->s_c_2[scor2->size].name = buf;
				ifs >> buf;
			}

			else if (i == 3)
			{
				int sex = 0;
				if (buf ==(string) "男")
				{
					sex = 1;
				}

				else if(buf == (string)"女")
				{
					sex = 2;
				}

				infor2->s_i_2[infor2->size].sex = sex;
				ifs >> buf;
			}

			else if (i == 4)
			{
				infor2->s_i_2[infor2->size].clas = buf;
				scor2->s_c_2[scor2->size].clas = buf;
				ifs >> buf;
			}

			else if (i == 5)
			{
				infor2->s_i_2[infor2->size].specialty = buf;
				ifs >> buf;
			}

			else if (i == 6)
			{
				infor2->s_i_2[infor2->size].research_direction = buf;
				ifs >> buf;
			}

			else if (i == 7)
			{
				infor2->s_i_2[infor2->size].tutor = buf;
				ifs >> buf;
			}

			else if (i == 8)
			{
				int all_class_score = 0;
				all_class_score = atoi(buf);
				scor2->s_c_2[scor2->size].all_class_score= all_class_score;
				ifs >> buf;
			}

			else if (i == 9)
			{
				int thesis = 0;
				thesis = atoi(buf);
				scor2->s_c_2[scor2->size].thesis = thesis;
				ifs >> buf;
			}

			else if (i == 10)
			{
				int sum_score = 0;
				sum_score = atoi(buf);
				scor2->s_c_2[scor2->size].sum_score= sum_score;
				ifs >> buf;
			}

			else if (i == 11)
			{
				int class_ranking = 0;
				class_ranking = atoi(buf);
				scor2->s_c_2[scor2->size].class_ranking = class_ranking;
				ifs >> buf;
			}

			else if (i == 12)
			{
				int school_ranking = 0;
				school_ranking = atoi(buf);
				scor2->s_c_2[scor2->size].school_ranking = school_ranking;
			}
		}

		infor2->size++;
		scor2->size++;
	}

	ifs.close();
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

	//生成随机的学号
	long int student_number;
	student_number = infor2->size + 20190001;
	infor2->s_i_2[infor2->size].student_number = student_number;

	//
	infor2->size++;

	system("cls");
}

void putout_information2(information2* infor2)
{
	for_information(infor2, 0, 10);
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
			for_information(infor2, 0, 10);
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
				for_information(infor2, 0, 10);
			}

			else if (num - 10 >= 0)
			{
				num = num - 10;
				for_information(infor2, num, num + 10);
			}
		}
		break;
		case 4:
			//下一页

			if (num + 10 > infor2->size)
			{
				cout << "已是尾页" << endl;
				system("pause");
				system("cls");
				for_information(infor2, num, infor2->size);
			}

			else if (num + 20 > infor2->size)
			{
				num = num + 10;
				for_information(infor2, num, infor2->size);
			}

			else
			{
				num = num + 10;
				for_information(infor2, num, num + 10);
			}

			break;
		case 5:
		{
			//尾页
			if (infor2->size % 10 == 0)
			{
				num = infor2->size - 10;
			}

			else if (infor2->size % 10 != 0)
			{
				num = infor2->size - (infor2->size % 10);
			}
			for_information(infor2, num, infor2->size);
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

int check_information2(information2* infor2)
{
	//判断该学生学号是否存在
	cout << "请输入学生学号：" << endl;
	long int student_number;
	cin >> student_number;
	for (int i = 0; i < infor2->size; i++)
	{
		if (infor2->s_i_2[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_information2(information2* infor2)
{

	int test = check_information2(infor2);
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
		cout << "5.研究方向" << endl;
		cout << "6.导师" << endl;

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "请输入姓名:" << endl;
			string name;
			cin >> name;
			infor2->s_i_2[test].name = name;
			break;
		}
		case 2:
		{
			cout << "请输入性别:" << endl;
			cout << "1-男" << endl;
			cout << "2-女" << endl;
			int sex;
			cin >> sex;
			infor2->s_i_2[test].sex = sex;
			break;
		}
		case 3:
		{
			cout << "请输入班级:" << endl;
			string clas;
			cin >> clas;
			infor2->s_i_2[test].clas = clas;
			break;
		}
		case 4:
		{
			cout << "请输入专业:" << endl;
			string specialty;
			cin >> specialty;
			infor2->s_i_2[test].specialty = specialty;
			break;
		}
		case 5:
		{
			cout << "请输入研究方向：" << endl;
			string research_direction;
			cin >> research_direction;
			infor2->s_i_2[test].research_direction = research_direction;
			break;
		}
		case 6:
		{
			cout << "请输入导师姓名：" << endl;
			string tutor;
			cin >> tutor;
			infor2->s_i_2[test].tutor = tutor;
			break;
		}
		}
		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}

void delect_information2(information2* infor2)
{
	int test = check_information2(infor2);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		//删除学生信息
		//通过将后一位学生的信息覆盖前一位学生的信息的方法实现学生信息的删除
		for (int i = test; i < infor2->size + 1; i++)
		{
			infor2->s_i_2[i] = infor2->s_i_2[i + 1];
		}
		infor2->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void look_information2(information2* infor2)
{
	cout << "1.查询个人信息" << endl;
	cout << "2.查询班级信息" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		look_one_information2(infor2);
	}

	else if (select == 2)
	{
		look_class_information2(infor2);
	}
}

int check_person(score2* scor2, information2* infor2)
{
	int num = 0;

	//判断学生信息系统中是否存在该学生姓名

	for (int i = 0; i < infor2->size; i++)
	{
		if (scor2->s_c_2[scor2->size].name == infor2->s_i_2[i].name)
		{
			scor2->s_c_2[scor2->size].student_number = infor2->s_i_2[i].student_number;
			return 1;
			break;
		}

		else {
			num++;
		}
	}

	if (num == infor2->size)
	{
		return -1;
	}

	return 0;
}

void input_score(score2* scor2, information2* infor2)
{
	cout << "请输入姓名:" << endl;
	string name;
	cin >> name;
	scor2->s_c_2[scor2->size].name = name;

	int test = check_person(scor2, infor2);

	if (test == -1)
	{
		cout << "学生信息管理系统中查无此人，请检查是否输入正确！" << endl;
	}

	else
	{
		cout << "请输入班级:" << endl;
		string clas;
		cin >> clas;
		scor2->s_c_2[scor2->size].clas = clas;


		cout << "课程总成绩成绩：" << endl;
		int all_class_score;
		cin >> all_class_score;
		scor2->s_c_2[scor2->size].all_class_score = all_class_score;

		cout << "论文成绩：" << endl;
		int thesis;
		cin >> thesis;
		scor2->s_c_2[scor2->size].thesis = thesis;

		//计算总成绩
		int sum = 0;
		if (thesis != -1 && all_class_score != -1)
		{
			sum = scor2->s_c_2[scor2->size].thesis + scor2->s_c_2[scor2->size].all_class_score;
		}

		scor2->s_c_2[scor2->size].sum_score = sum;

		scor2->size++;

		cout_ranking(scor2);//计算排名
	}
	system("pause");
	system("cls");
}

void cout_ranking(score2* scor2)
{
	for (int i = 0; i < scor2->size; i++)
	{
		for (int j = 0; j < scor2->size; j++)
		{
			//通过冒泡排序对学生总成绩进行排名
			if (scor2->s_c_2[j].sum_score < scor2->s_c_2[j + 1].sum_score)
			{
				//对比总成绩，互换学生的结构体次序
				struct student_score2 temp = scor2->s_c_2[j];
				scor2->s_c_2[j] = scor2->s_c_2[j + 1];
				scor2->s_c_2[j + 1] = temp;
			}
		}
	}

	for (int k = 0; k < scor2->size; k++)
	{
		scor2->s_c_2[k].school_ranking = k + 1;
	}
}

int check_number(score2* scor2)
{
	//查询学生学号
	cout << "请输入学生学号：" << endl;
	long int student_number;
	cin >> student_number;
	for (int i = 0; i < scor2->size; i++)
	{
		//查到学生学号，返回学生在结构体中的的学号
		if (scor2->s_c_2[i].student_number == student_number)
		{
			return i;
		}
	}
	//没查到则返回-1
	return -1;
}

void change_score(score2* scor2)
{
	int test = check_number(scor2);
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
			cout << "3.课程总成绩成绩" << endl;
			cout << "4.论文成绩" << endl;
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
					scor2->s_c_2[test].name = name;
					break;
				}
				case 2:
				{
					cout << "请输入班级:" << endl;
					string clas;
					cin >> clas;
					scor2->s_c_2[test].clas = clas;
					break;
				}
				case 3:
				{
					cout << "课程总成绩成绩：" << endl;
					int all_class_score;
					cin >> all_class_score;
					scor2->s_c_2[test].all_class_score = all_class_score;
					break;
				}
				case 4:
				{
					cout << "论文成绩：" << endl;
					int thesis;
					cin >> thesis;
					scor2->s_c_2[test].thesis = thesis;
					break;
				}
				}
				system("cls");
			}
		}
		cout << "修改成功" << endl;

		//重新计算总成绩以及总排名
		int sum = 0;
		if (scor2->s_c_2[test].all_class_score != -1 && scor2->s_c_2[test].thesis != -1)
		{
			sum = scor2->s_c_2[test].all_class_score + scor2->s_c_2[test].thesis;
		}

		scor2->s_c_2[test].sum_score = sum;

		cout_ranking(scor2);
	}
	system("pause");
	system("cls");
}

void delect_student(score2* scor2)
{
	int test = check_number(scor2);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		//通过将后一位学生的信息成绩前一位学生的信息的方法实现学生成绩的删除
		for (int i = test; i < scor2->size + 1; i++)
		{
			scor2->s_c_2[i] = scor2->s_c_2[i + 1];
		}
		scor2->size--;
		cout << "删除成功" << endl;
	}
	cout_ranking(scor2);
	system("pause");
	system("cls");
}

void look_score(score2* scor2)
{
	cout << "1.查询个人成绩" << endl;
	cout << "2.查询班级成绩" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		look_one_score2(scor2);
	}

	else if (select == 2)
	{
		look_class_score2(scor2);
	}
}

void putout_score(score2* scor2)
{
	for_score(scor2, 0, 10);
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
			for_score(scor2, 0, 10);
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
				for_score(scor2, 0, 10);
			}

			else if (num - 10 >= 0)
			{
				num = num - 10;
				for_score(scor2, num, num + 10);
			}
		}
		break;
		case 4:
			//下一页

			if (num + 10 > scor2->size)
			{
				cout << "已是尾页" << endl;
				system("pause");
				system("cls");
				for_score(scor2, num, scor2->size);
			}

			else if (num + 20 > scor2->size)
			{
				num = num + 10;
				for_score(scor2, num, scor2->size);
			}

			else
			{
				num = num + 10;
				for_score(scor2, num, num + 10);
			}

			break;
		case 5:
		{
			//尾页
			if (scor2->size % 10 == 0)
			{
				num = scor2->size - 10;
			}

			else if (scor2->size % 10 != 0)
			{
				num = scor2->size - (scor2->size % 10);
			}
			for_score(scor2, num, scor2->size);
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

void class_management(score2 *scor2, string* arr, all_class* a_c)
{
	//先将每个学生的班级输入到一个数组中再进行查重去除重复的班级
	for (int i = 0; i < scor2->size; i++)
	{
		arr[i] = scor2->s_c_2[i].clas;
	}

	string temp[100];
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

	for (int n = 0; n < m-1; n++)
	{
		a_c->o_c[a_c->size].clas = temp[n];
		a_c->size++;
	}


//遍历已经排好总成绩的学生，将每个学生分到对应的班级中，根据每个学生进入班级的次序对其进行排名
	//i代表数组中的班级序号，从结构体中遍历学生所属的班级与序号为i的班级进行对比
	for (int i = 0; i < a_c->size; i++)
	{
		//j代表班级中的排名，从结构体中选中符合i代表的班级的学生，从第一名开始进行排名
		int k = 0;
		for (int j = 0; j < 100; j++)
		{
			//k代表结构体中学生的序号，从结构体中寻找符合上述条件的学生，如果从第k序号找到，为其赋予排名，再从k+1序号继续寻找，直到遍历完所有学生
			for (; k < scor2->size; k++)
			{
				//班级名不能的是空的
				if (scor2->s_c_2[k].clas != " ")
				{
					//遍历的学生班级要与班级数组中第i个班级的名称一致
					if (scor2->s_c_2[k].clas == a_c->o_c[i].clas)
					{
						a_c->o_c[i].all_class_score_sum = a_c->o_c[i].all_class_score_sum + scor2->s_c_2[k].all_class_score;
						a_c->o_c[i].thesis_sum = a_c->o_c[i].thesis_sum + scor2->s_c_2[k].thesis;
						scor2->s_c_2[k].class_ranking = j + 1;
						a_c->o_c[i].size++;
						cout_abc(i,k,scor2,a_c);
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

int check_number_file(score2* scor2, int number)
{
	for (int i = 0; i < scor2->size; i++)
	{
		if (scor2->s_c_2[i].student_number == number)
		{
			return i;
		}
	}
	return -1;
}

void cout_class(all_class* a_c)
{
	cout << "1.班级平均成绩" << endl;
	cout << "2.班级课程分数等级统计" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		cout_ave(a_c);
		break;

	case 2:
		print(a_c);
		break;

	default:
		break;
	}
}

void cout_ave(all_class* a_c)
{
	for (int i = 0; i < a_c->size; i++)
	{
		a_c->o_c[i].all_class_ave = a_c->o_c[i].all_class_score_sum / (a_c->o_c[i].size * 1.0);
		a_c->o_c[i].thesic_ave = a_c->o_c[i].thesis_sum / (a_c->o_c[i].size * 1.0);
	}

	for (int j = 0; j < a_c->size; j++)
	{
		cout << "班级：" << a_c->o_c[j].clas << "   "
			<< "课程总成绩平均分:" << a_c->o_c[j].all_class_ave << "   "
			<< "论文平均分:" << a_c->o_c[j].thesic_ave << endl;
	}

	system("pause");
	system("cls");
}

void cout_abc(int i, int k, score2* scor2, all_class* a_c)
{
	int num = 1;
	judje(scor2->s_c_2[k].all_class_score,num,i,a_c);
	num = 2;
	judje(scor2->s_c_2[k].thesis,num,i,a_c);
}

void judje(int score,int num,int i, all_class* a_c)
{
	if (score >= 90)
	{
		if (num == 1)
			a_c->o_c[i].a++;

		else if (num == 2)
			a_c->o_c[i].a2++;
	}

	else if (score < 90 && score >= 80)
	{
		if (num == 1)
			a_c->o_c[i].b++;

		else if (num == 2)
			a_c->o_c[i].b2++;
	}

	else if (score < 80 && score >= 70)
	{
		if (num == 1)
			a_c->o_c[i].c++;

		else if (num == 2)
			a_c->o_c[i].c2++;
	}

	else if (score < 70 && score >= 60)
	{
		if (num == 1)
			a_c->o_c[i].d++;

		else if (num == 2)
			a_c->o_c[i].d2++;
	}

	else if (score < 60)
	{
		if (num == 1)
			a_c->o_c[i].e++;

		else if (num == 2)
			a_c->o_c[i].e2++;
	}
}

void print(all_class *a_c)
{
	cout << "请输入班级名称" << endl;
	string clas;
	cin >> clas;
	int text = check_class(clas, a_c);

	system("cls");

	cout << "请输入要统计的科目:" << endl;
	cout << "1.课程总成绩" << endl;
	cout << "2.论文成绩" << endl;
	int select = 0;
	cin >> select;

	system("cls");

	if (select == 1)
	{
		cout << "优秀:" <<a_c->o_c[text].a<<"   "
			 << "良好:" << a_c->o_c[text].b << "   "
			 << "中等:" << a_c->o_c[text].c << "   "
			 << "及格:" << a_c->o_c[text].d << "   "
			 << "不及格:" << a_c->o_c[text].e << "   "
			 << endl;
	}

	else if (select == 2)
	{
		cout << "优秀:" << a_c->o_c[text].a2 << "   "
			<< "良好:" << a_c->o_c[text].b2 << "   "
			<< "中等:" << a_c->o_c[text].c2 << "   "
			<< "及格:" << a_c->o_c[text].d2 << "   "
			<< "不及格:" << a_c->o_c[text].e2 << "   "
			<< endl;
	}
	system("pause");
	system("cls");
}

int check_class(string clas, all_class* a_c)
{
	for (int i = 0; i < a_c->size; i++)
	{
		if (a_c->o_c[i].clas == clas)
		{
			return i;
		}
	}

	return -1;
}

void for_information(information2* infor2, int i, int j)
{
	for (; i < j; i++)
	{
		//输出成绩
		cout << "姓名:" << infor2->s_i_2[i].name << "   "
			<< "性别:" << (infor2->s_i_2[i].sex == 1 ? "男" : "女") << "   "
			<< "班级:" << infor2->s_i_2[i].clas << "   "
			<< "专业:" << infor2->s_i_2[i].specialty << "   "
			<< "研究方向:" << infor2->s_i_2[i].research_direction << "   "
			<< "导师:" << infor2->s_i_2[i].tutor << "   "
			<< "学号:" << infor2->s_i_2[i].student_number << endl;
	}

	cout << "1.首页" << "   " << "2.目录" << "   " << "3.上一页" << "   " << "4.下一页" << "   " << "5.尾页" << endl;
}

void for_score(score2* scor2, int i, int j)
{
	for (; i < j; i++)
	{
		cout << "姓名:" << scor2->s_c_2[i].name << "   "
			<< "学号:" << scor2->s_c_2[i].student_number << "   "
			<< "班级:" << scor2->s_c_2[i].clas << "   "
			<< "课程总成绩:" << scor2->s_c_2[i].all_class_score << "   "
			<< "论文成绩:" << scor2->s_c_2[i].thesis << "   "
			<< "总成绩" << scor2->s_c_2[i].sum_score << "   "
			<< "班排名" << scor2->s_c_2[i].class_ranking << "   "
			<< "校排名:" << scor2->s_c_2[i].school_ranking << endl;
	}

	cout << "1.首页" << "   " << "2.目录" << "   " << "3.上一页" << "   " << "4.下一页" << "   " << "5.尾页" << endl;
}

void look_one_information2(information2* infor2)
{
	int test = check_information2(infor2);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else
	{
		//个人信息输出
		cout << "姓名:" << infor2->s_i_2[test].name << "   "
			<< "性别:" << (infor2->s_i_2[test].sex == 1 ? "男" : "女") << "   "
			<< "班级:" << infor2->s_i_2[test].clas << "   "
			<< "专业:" << infor2->s_i_2[test].specialty << "   "
			<< "研究方向:" << infor2->s_i_2[test].research_direction << "   "
			<< "导师:" << infor2->s_i_2[test].tutor << "   "
			<< "学号:" << infor2->s_i_2[test].student_number << endl;
	}
	system("pause");
	system("cls");
}

void look_one_score2(score2* scor2)
{
	int test = check_number(scor2);
	if (test == -1)
	{
		cout << "该学号不存在，请重新输入" << endl;
	}

	else {
		cout << "姓名:" << scor2->s_c_2[test].name << "   "
			<< "学号:" << scor2->s_c_2[test].student_number << "   "
			<< "班级:" << scor2->s_c_2[test].clas << "   "
			<< "课程总成绩:" << scor2->s_c_2[test].all_class_score << "   "
			<< "论文成绩:" << scor2->s_c_2[test].thesis << "   "
			<< "总成绩" << scor2->s_c_2[test].sum_score << "   "
			<< "校排名:" << scor2->s_c_2[test].school_ranking << endl;
	}
	system("pause");
	system("cls");
}

void look_class_information2(information2* infor2)
{
	string clas = " ";
	cout << "请输入班级：";
	cin >> clas;
	int test = 0;
	for (int i = 0; i < infor2->size; i++)
	{
		if (infor2->s_i_2[i].clas == clas)
		{
			cout << "姓名:" << infor2->s_i_2[i].name << "   "
				<< "性别:" << (infor2->s_i_2[i].sex == 1 ? "男" : "女") << "   "
				<< "班级:" << infor2->s_i_2[i].clas << "   "
				<< "专业:" << infor2->s_i_2[i].specialty << "   "
				<< "研究方向:" << infor2->s_i_2[i].research_direction << "   "
				<< "导师:" << infor2->s_i_2[i].tutor << "   "
				<< "学号:" << infor2->s_i_2[i].student_number << endl;
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

void look_class_score2(score2* scor2)
{
	string clas = " ";
	cout << "请输入班级：";
	cin >> clas;
	int test = 0;

	for (int i = 0; i < scor2->size; i++)
	{
		if (scor2->s_c_2[i].clas == clas)
		{
			cout << "姓名:" << scor2->s_c_2[i].name << "   "
				<< "学号:" << scor2->s_c_2[i].student_number << "   "
				<< "班级:" << scor2->s_c_2[i].clas << "   "
				<< "课程总成绩:" << scor2->s_c_2[i].all_class_score << "   "
				<< "论文成绩:" << scor2->s_c_2[i].thesis << "   "
				<< "总成绩" << scor2->s_c_2[i].sum_score << "   "
				<< "班排名" << scor2->s_c_2[i].class_ranking << "   "
				<< "校排名:" << scor2->s_c_2[i].school_ranking << endl;
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