#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define MAX 10000

using namespace std;

struct student_information2;
struct information2;
struct student_score2;
struct score2;

int yan_student_system();//研究生管理系统
void yan_student_information_system();//研究生信息管理系统
void yan_student_score_system();//研究生成绩管理系统 
void input_information2(information2* infor2);//信息输入的函数
void putout_information2(information2* infor2);//信息输出函数
int check_information2(information2* infor2);//查询学号的函数
void change_information2(information2* infor2);//修改信息的函数
void delect_information2(information2* infor2);//删除信息的函数
void look_information2(information2* infor2);//查询个人信息的函数

int check_person(score2* scor2, information2* infor2);//判断查询信息系统中是否有输入学生姓名的函数
void input_score(score2* scor2, information2* infor2);//成绩输入的函数
void cout_ranking(score2* scor2);//计算学校总排名的函数