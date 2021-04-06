#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define MAX 10000
using namespace std;
/*
学生基本信息管理系统
	1.学生基本信息输入 
	（1）本科生输入姓名，班级，专业，性别，自动生成学号 
	（2）研究生输入姓名，班级，专业，性别，研究方向，导师，自动生成学号 
	
	2.学生基本信息修改
	（1）修改除学号外任意基本资料
	
	3.删除学生基本资料
	（1）根据学号删除一个学生
	
	4.查询学生基本资料
	（1）根据学号查询学生基本资料 
	
	
成绩管理系统 
	1.输入成绩
	
	2.计算成绩
	(1) 总成绩的计算
	(2) 排名的计算(班排和校排） 
	(3) 总成绩排序(按班级和学校进行) 
	
	3.查询成绩
	(1)根据学号查询学生个人成绩
	(2)可以(分页)显示全部学生成绩
	(3)可以查询某班级中不及格学生信息
	 
	4.修改成绩
	(1)根据学生学号可以对某门课程进行修改
	(2)修改前显示该学生成绩
	 
	5.删除成绩
	(1)根据学生学号进行删除 
	
	7.退出系统 
*/
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
};

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
};

void input_information1(information1 *infor1);
void change_information1(information1 *infor1); 
void putout_information1(information1 *infor1);
int check_information1(information1 *infor1); 
void delect_information1(information1 *infor1);
void look_information1(information1 *infor1);

void input_score(score *scor,information1 *infor1);
void cout_ranking(score *scor);
int check_person(score *scor,information1 *infor1);
int check_number(score *scor);
void change_score(score *scor);
void delect_student(score *scor);
void putout_score(score *scor);
void look_score(score *scor);
void class_management(score *scor,string *arr);


int main(){
	struct information1 infor1;
	struct score scor;
	srand((unsigned int)time(NULL));
	string  arr[100];
	
   	ifstream ifs;
   	ifs.open("C:\\Users\\pqy18770657781\\Desktop\\学生成绩管理系统.xls",ios::in);
   	char temp;
	while((temp = getline())!=0
	
	
	
	int select1,select2;
	
	while(true)
	{
		cout<<"1.本科生信息管理系统"<<endl;
		cout<<"2.本科生成绩管理系统"<<endl;
		cout<<"3.将信息成绩输入表格"<<endl;
		cout<<"3.退出学生管理系统"<<endl; 
		cin>>select1;
		system("cls");

		if(select1 == 1)
		{
			while(true)
			{
			cout<<"1.学生基本信息输入 "<<endl;
			cout<<"2.学生基本信息修改 "<<endl;
			cout<<"3.删除学生基本资料 "<<endl;
			cout<<"4.查询学生基本资料 "<<endl;
			cout<<"5.输出学生基本资料 "<<endl;
			cout<<"6.退出信息管理系统 "<<endl;
			cin>>select2;
			system("cls");
			if(select2==6)
			{
				break;
			}
			switch(select2)
			{
				case 1:
					input_information1(&infor1);
					break;
				case 2:
					change_information1(&infor1);
					break;
				case 3:
					delect_information1(&infor1);
					break;
				case 4:
					look_information1(&infor1);
					break;
				case 5:
					putout_information1(&infor1);
					break;
			}
			}
		}

		else if(select1 == 2)
		{
			while(true)
		{	
			cout<<"  1.学生成绩输入 "<<endl;
			cout<<"  2.学生成绩计算 "<<endl;
			cout<<"  3.学生成绩修改 "<<endl;
			cout<<"  4.学生成绩删除 "<<endl;
			cout<<"  5.学生成绩查询 "<<endl;
			cout<<"  6.学生成绩输出 "<<endl;
			cout<<"7.退出成绩管理系统 "<<endl;
			cin>>select2;
			system("cls");
			if(select2==7)
			{
				break;
			}		
			switch(select2)
			{
				case 1:
					input_score(&scor,&infor1);
					break;
				case 2:
					class_management(&scor,arr);
					break;
				case 3:
				{
					change_score(&scor);
					cout_ranking(&scor);
					break;
				}
				case 4:
					delect_student(&scor);
					break;
				case 5:
					look_score(&scor);
					break;
				case 6:
					putout_score(&scor);
					break;								
			}
		}
		}
		
		else if(select1==3)
		{
			ofstream ofs;
			ofs.open("C:\\Users\\pqy18770657781\\Desktop\\学生成绩管理系统.xls",ios::app);
			ofs<<"学号\t"<<"姓名\t"<<"性别\t"<<"班级\t"<<"专业\t"<<"高数\t"<<"英语\t"<<"C语言\t"<<"总成绩\t"<<"班排名\t"<<"校排名\n";
			for(int i=0;i<infor1.size;i++)
			{
				ofs<<infor1.s_i_1[i].student_number<<"\t"
				   <<infor1.s_i_1[i].name<<"\t"
				   <<(infor1.s_i_1[i].sex==1?"男":"女")<<"\t"
				   <<infor1.s_i_1[i].clas<<"\t"
				   <<infor1.s_i_1[i].specialty<<"\t"
				   <<scor.s_c[i].high_math<<"\t"
				  <<scor.s_c[i].english<<"\t"
				  <<scor.s_c[i].c_language<<"\t"
				  <<scor.s_c[i].sum_score<<"\t"
				  <<scor.s_c[i].class_ranking<<"\t"
				  <<scor.s_c[i].school_ranking<<"\t"
				  <<endl;
			}
			ofs.close();
			cout<<"输入成功！"<<endl;
			system("pause");
			system("cls");
		}
		
		
		else if(select1==4)
		{
			system("pause");
			return 0;
		}
	}

}

void input_information1(information1 *infor1)
{
	cout<<"请输入姓名:"<<endl;
	string name;
	cin>>name;
	infor1->s_i_1[infor1->size].name = name;
	
	cout<<"请输入性别:"<<endl;
	cout<<"1-男"<<endl;
	cout<<"2-女"<<endl;
	int sex;
	cin>>sex;
	infor1->s_i_1[infor1->size].sex = sex;
	
	cout<<"请输入班级:"<<endl;
	string clas;
	cin>>clas;
	infor1->s_i_1[infor1->size].clas = clas;
	
	cout<<"请输入专业:"<<endl;
	string specialty;
	cin>>specialty;
	infor1->s_i_1[infor1->size].specialty = specialty;
	
	long int student_number;
	student_number = rand()%10000 + 20200000;
	infor1->s_i_1[infor1->size].student_number = student_number;
	
	infor1->size++;
	
	system("cls");
}

int check_information1(information1 *infor1)
{
	cout<<"请输入学生学号："<<endl;
	long int student_number;
	cin>>student_number;
	for(int i=0;i<infor1->size;i++)
	{
		if(infor1->s_i_1[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_information1(information1 *infor1)
{
	int test = check_information1(infor1);
	if(test == -1)
	{
		cout<<"该学号不存在，请重新输入"<<endl; 
	}
	
	else
	{
		cout<<"请输入修改信息："<<endl;
		cout<<"1.姓名"<<endl;
		cout<<"2.性别"<<endl;
		cout<<"3.班级"<<endl;
		cout<<"4.专业"<<endl;
		
		int select;
		cin>>select;
		switch(select)
		{
			case 1:
				{
				cout<<"请输入姓名:"<<endl;
				string name;
				cin>>name;
				infor1->s_i_1[test].name = name;
				break;	
				}
			case 2:
				{
				cout<<"请输入性别:"<<endl;
				cout<<"1-男"<<endl;
				cout<<"2-女"<<endl;
				int sex;
				cin>>sex;
				infor1->s_i_1[test].sex = sex;
				break;
				}
			case 3:
				{
				cout<<"请输入班级:"<<endl;
				string clas;
				cin>>clas;
				infor1->s_i_1[test].clas = clas;
				break;
				}
			case 4:
				{
				cout<<"请输入专业:"<<endl;
				string specialty;
				cin>>specialty;
				infor1->s_i_1[test].specialty = specialty;
				break;	
				}	
		} 
		cout<<"修改成功！"<<endl;
	}
	system("pause");
	system("cls");
}

void delect_information1(information1 *infor1)
{
	int test = check_information1(infor1);
		if(test == -1)
		{
			cout<<"该学号不存在，请重新输入"<<endl; 
		}
		
		else
		{
			for(int i=test;i<infor1->size+1;i++)
			{
				infor1->s_i_1[i] = infor1->s_i_1[i+1];
			}
			infor1->size--;
			cout<<"删除成功"<<endl; 
		}
	system("pause");
	system("cls"); 
}

void look_information1(information1 *infor1)
{
	int test = check_information1(infor1);
		if(test == -1)
		{
			cout<<"该学号不存在，请重新输入"<<endl; 
		}
		
		else
		{
			cout<<"姓名:"<<infor1->s_i_1[test].name<<"   "
			<<"性别:"<<(infor1->s_i_1[test].sex==1?"男":"女")<<"   "
			<<"班级:" <<infor1->s_i_1[test].clas<<"   "
			<<"专业:"<<infor1->s_i_1[test].specialty<<"   "
			<<"学号:"<<infor1->s_i_1[test].student_number<<endl;
		}
		system("pause");
		system("cls");
}

void putout_information1(information1 *infor1)
{
	for(int i=0;i<infor1->size;i++)
	{
		cout<<"姓名:"<<infor1->s_i_1[i].name<<"   "
		<<"性别:"<<(infor1->s_i_1[i].sex==1?"男":"女")<<"   "
		<<"班级:" <<infor1->s_i_1[i].clas<<"   "
		<<"专业:"<<infor1->s_i_1[i].specialty<<"   "
		<<"学号:"<<infor1->s_i_1[i].student_number<<endl;
	}
	 
	system("pause");
	system("cls");
}

void input_score(score *scor,information1 *infor1)
{
	cout<<"请输入姓名:"<<endl;
	string name;
	cin>>name;
	scor->s_c[scor->size].name = name;
	
	int test = check_person(scor,infor1);
		
	if(test == -1)
	{
		cout<<"学生信息管理系统中查无此人，请检查是否输入正确！"<<endl; 
	}
	
	else
	{
	cout<<"请输入班级:"<<endl;
	string clas;
	cin>>clas;
	scor->s_c[scor->size].clas = clas;
	
	
	cout<<"高数成绩："<<endl;
	int high_math;
	cin>>high_math;
	scor->s_c[scor->size].high_math = high_math;
	
	cout<<"英语成绩："<<endl;
	int english;
	cin>>english;
	scor->s_c[scor->size].english = english;
	
	cout<<"c语言成绩："<<endl;
	int c_language;
	cin>>c_language;
	scor->s_c[scor->size].c_language = c_language;	
		
	int sum;
	sum = scor->s_c[scor->size].high_math + scor->s_c[scor->size].english + scor->s_c[scor->size].c_language;
	scor->s_c[scor->size].sum_score = sum;

	scor->size++;
	
	cout_ranking(scor);			
	}
	system("pause");
	system("cls");
}

void cout_ranking(score *scor)
{
	for(int i=0;i<scor->size;i++)
	{
		for(int j=0;j<scor->size;j++)
		{
			if(scor->s_c[j].sum_score<scor->s_c[j+1].sum_score)
			{
				struct student_score temp = scor->s_c[j];
				scor->s_c[j] = scor->s_c[j+1];
				scor->s_c[j+1] = temp;
			}
		}
	}	
	
	for(int k=0;k<scor->size;k++)
	{
		scor->s_c[k].school_ranking = k+1;
	}
}

void putout_score(score *scor)
{
	for(int i=0;i<scor->size;i++)
	{
		cout<<"姓名:"<<scor->s_c[i].name<<"   "
		<<"学号:"<<scor->s_c[i].student_number<<"   "
		<<"班级:"<<scor->s_c[i].clas<<"   " 
		<<"高数:"<<scor->s_c[i].high_math<<"   "
		<<"英语:"<<scor->s_c[i].english<<"   "
		<<"c语言:"<<scor->s_c[i].c_language<<"   "
		<<"总成绩"<<scor->s_c[i].sum_score<<"   "
		<<"班排名"<<scor->s_c[i].class_ranking<<"   " 
		<<"校排名:"<<scor->s_c[i].school_ranking<<endl;
	}
	system("pause");
	system("cls");
}

int check_person(score *scor,information1 *infor1)
{
	int num = 0;
	
	for(int i=0;i<infor1->size;i++)
	{
		if(scor->s_c[scor->size].name == infor1->s_i_1[i].name)
		{
			scor->s_c[scor->size].student_number = infor1->s_i_1[i].student_number;
			return 1;
			break;
		}
		
		else{
			num++;
		}
	}
	
	if(num==infor1->size)
	{
		return -1;
	}
	
	return 0;
}

int check_number(score *scor)
{
	cout<<"请输入学生学号："<<endl;
	long int student_number;
	cin>>student_number;
	for(int i=0;i<scor->size;i++)
	{
		if(scor->s_c[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_score(score *scor)
{
	int test = check_number(scor);
	if(test == -1)
	{
		cout<<"该学号不存在，请重新输入"<<endl; 
	}
	
	else
	{
		while(true)
		{	
			cout<<"请输入修改信息："<<endl;
			cout<<"1.姓名"<<endl;
			cout<<"2.班级"<<endl;
			cout<<"3.高数成绩"<<endl;
			cout<<"4.英语成绩"<<endl;
			cout<<"5.c语言成绩"<<endl;
			cout<<"6.退出修改"<<endl;
			
			int select;
			cin>>select;
			if(select==6)
			{
				break;
			}
			
			else
			{
				switch(select)
				{
				case 1:
					{
					cout<<"请输入姓名:"<<endl;
					string name;
					cin>>name;
					scor->s_c[test].name = name;
					break;					
					}
				case 2:
					{
					cout<<"请输入班级:"<<endl;
					string clas;
					cin>>clas;
					scor->s_c[test].clas = clas;	
					break;	
					}
				case 3:
					{
					cout<<"高数成绩："<<endl;
					int high_math;
					cin>>high_math;
					scor->s_c[test].high_math = high_math;
					break;		
					}
				case 4:
					{
					cout<<"英语成绩："<<endl;
					int english;
					cin>>english;
					scor->s_c[test].english = english;
					break;		
					}
				case 5:
					{
					cout<<"c语言成绩："<<endl;
					int c_language;
					cin>>c_language;
					scor->s_c[test].c_language = c_language;		
					}
				}
			system("cls");
			}
		}
	cout<<"修改成功"<<endl;	
	int sum;
	sum = scor->s_c[test].high_math + scor->s_c[test].english + scor->s_c[test].c_language;
	scor->s_c[test].sum_score = sum;
	
	cout_ranking(scor);
	}
	system("pause");
	system("cls");
}

void delect_student(score *scor)
{
	int test = check_number(scor);
	if(test == -1)
	{
		cout<<"该学号不存在，请重新输入"<<endl; 
	}
			
	else
	{
		for(int i=test;i<scor->size+1;i++)
		{
			scor->s_c[i] = scor->s_c[i+1];
		}
		scor->size--;
		cout<<"删除成功"<<endl; 
	}
	cout_ranking(scor);
	system("pause");
	system("cls"); 
}

void look_score(score *scor)
{
	int test = check_number(scor);
	if(test == -1)
	{
		cout<<"该学号不存在，请重新输入"<<endl; 
	}
	
	else{
	cout<<"姓名:"<<scor->s_c[test].name<<"   "
	<<"学号:"<<scor->s_c[test].student_number<<"   "
	<<"班级:"<<scor->s_c[test].clas<<"   " 
	<<"高数:"<<scor->s_c[test].high_math<<"   "
	<<"英语:"<<scor->s_c[test].english<<"   "
	<<"c语言:"<<scor->s_c[test].c_language<<"   "
	<<"总成绩"<<scor->s_c[test].sum_score<<"   "
	<<"校排名:"<<scor->s_c[test].school_ranking<<endl;		
	}
	system("pause");
	system("cls");
}

void class_management(score *scor,string *arr)
{
	for(int i=0;i<scor->size;i++)
	{
		arr[i] = scor->s_c[i].clas;
	}
		
	string temp[100];
	int m = 0;
	for(int j=0;j<100;j++)
	{
		int k = 0;
		for(;k<m;k++)
		{
			if(arr[j]==temp[k])
			{
				break;
			}
		}
			
		if(k == m)
		{
			temp[m] = arr[j];
			m++;
		}
	}
	
	for(int i=0;i<100;i++)
	{
		int k=0;
		for(int j=0;j<100;j++)
		{
			for(;k<scor->size;k++)
			{
				if(scor->s_c[k].clas != " ")
				{
					if(scor->s_c[k].clas == temp[i])
					{
						scor->s_c[k].class_ranking = j+1;
						k = k+1;
						break;
					}		
				}
			}
		}
	} 
	cout<<"计算完成"<<endl;
	system("pause");
	system("cls");
}
