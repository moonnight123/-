#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define MAX 10000

using namespace std;

struct student_information1;
struct information1;
struct student_information1;
struct score;
struct one_class0;
struct all_class0;

int ben_student_system();//本科生系统
void ben_student_information_system();//本科生信息管理系统
void ben_student_score_system();//本科生成绩管理系统
void ben_putin_file(information1* infor1, score* scor);
void ben_putout_file();//将数据输入到excle表中
void input_information1(information1* infor1);//信息输入的函数
void putout_information1(information1* infor1);//信息输出函数
int check_information1(information1* infor1);//查询学号的函数
void change_information1(information1* infor1);//修改信息的函数
void delect_information1(information1* infor1);//删除信息的函数
void look_information1(information1* infor1);//查询个人信息的函数

void input_score(score* scor, information1* infor1);//成绩输入的函数
int check_person(score* scor, information1* infor1);//判断查询信息系统中是否有输入学生姓名的函数
void cout_ranking(score* scor);//计算学校总排名的函数
int check_number(score* scor);//查询本科生信息系统中学生的学号是否存在
void change_score(score* scor);//成绩修改的函数
void delect_student(score* scor);//成绩删除的函数
void look_score(score* scor);//查询成绩的函数
void putout_score(score* scor);//成绩输出的函数
void class_management(score* scor, string* arr,string *temp,all_class0*a_c_0);//班级排名的函数
int check_number_file(score* scor, int number);//检查成绩管理系统中是否有该学号的函数
void cout_class(all_class0* a_c_0);
void cout_ave(all_class0* a_c_0);
void cout_abc(int i, int k, score* scor, all_class0* a_c_0);
void judje(int score, int num, int i, all_class0* a_c_0);
void print(all_class0* a_c_0);
int check_class(string clas, all_class0* a_c_0);
void for_information(information1 *infor1,int i,int j);
void for_score(score* scor, int i, int j);
void look_one_information(information1* infor1);
void look_class_information(information1* infor1);
void look_one_score(score* scor);
void look_class_score(score* scor);
void look_the_bad_score_student(score* scor);
void look_the_bad_score(score* scor,int i,int score);