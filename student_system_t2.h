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

int yan_student_system();
void input_information2(information2* infor2);
void putout_information2(information2* infor2);
int check_information2(information2* infor2);
void change_information2(information2* infor2);
void delect_information2(information2* infor2);
void look_information2(information2* infor2);