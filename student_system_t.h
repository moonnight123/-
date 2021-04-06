#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define MAX 10000
using namespace std;
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
	int school_ranking =0;
	long int student_number = 0;
};

struct score2
{
	student_score2 s_c_2[MAX];
	int size = 0;
}scor2;

int ben_student_system();
void input_information1(information1* infor1);

int yan_student_system();
void input_information2(information2* infor2);