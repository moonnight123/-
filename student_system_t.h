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


int ben_student_system();//������ϵͳ
void ben_student_information_system();//��������Ϣ����ϵͳ
void ben_student_score_system();
void input_information1(information1* infor1);//��Ϣ����ĺ���
void putout_information1(information1* infor1);//��Ϣ�������
int check_information1(information1* infor1);//��ѯѧ�ŵĺ���
void change_information1(information1* infor1);//�޸���Ϣ�ĺ���
void delect_information1(information1* infor1);//ɾ����Ϣ�ĺ���
void look_information1(information1* infor1);//��ѯ������Ϣ�ĺ���

void input_score(score* scor, information1* infor1);//�ɼ�����ĺ���
int check_person(score* scor, information1* infor1);//�жϲ�ѯ��Ϣϵͳ���Ƿ�������ѧ�������ĺ���
void cout_ranking(score* scor);//����ѧУ�������ĺ���
int check_number(score* scor);//��ѯ��������Ϣϵͳ��ѧ����ѧ���Ƿ����
void change_score(score* scor);//�ɼ��޸ĵĺ���
void delect_student(score* scor);//�ɼ�ɾ���ĺ���
void look_score(score* scor);//��ѯ�ɼ��ĺ���
void putout_score(score* scor);//�ɼ�����ĺ���