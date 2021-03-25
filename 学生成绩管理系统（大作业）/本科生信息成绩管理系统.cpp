#include <iostream>
#include <string>
#include <ctime>
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
	string name;
	int sex;
	string clas;
	string specialty;
	long int student_number;	
};

struct information1
{
	student_information1 s_i_1[MAX];
	int size = 0;
};

void input_information1(information1 *infor1);
void change_information1(information1 *infor1); 
void putout_information1(information1 *infor1);
int check_information1(information1 *infor1); 
void delect_information1(information1 *infor1);
void look_information1(information1 *infor1);

int main(){
	struct information1 infor1;
	srand((unsigned int)time(NULL));
	int select1,select2;
	
	while(true)
	{
		cout<<"1.本科生信息管理系统"<<endl;
		cout<<"2.本科生成绩管理系统"<<endl;
		cin>>select1;
		system("cls");
		if(select1 == 1)
		{
			cout<<"1.学生基本信息输入 "<<endl;
			cout<<"2.学生基本信息修改 "<<endl;
			cout<<"3.删除学生基本资料 "<<endl;
			cout<<"4.查询学生基本资料 "<<endl;
			cout<<"5.输出学生基本资料 "<<endl;
			cout<<"6.退出信息管理系统 "<<endl;
			cin>>select2;
			system("cls");
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
				case 6:
					{
					system("pause");
					return 0;
					break;	
					}

			}
			
		}
		
		else if(select1 == 2)
		{
			
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
