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

int yan_student_system()
{
	int select1;

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
			input_score(&scor2, &infor2);
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
	student_number = rand() % 10000 + 20190000;
	infor2->s_i_2[infor2->size].student_number = student_number;

	//
	infor2->size++;

	system("cls");
}

void putout_information2(information2* infor2)
{
	for (int i = 0; i < infor2->size; i++)
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
		int sum;
		sum = scor2->s_c_2[scor2->size].thesis + scor2->s_c_2[scor2->size].all_class_score;
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