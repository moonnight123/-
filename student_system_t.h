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

int ben_student_system();//������ϵͳ
void ben_student_information_system();//��������Ϣ����ϵͳ
void ben_student_score_system();//�������ɼ�����ϵͳ
void ben_putin_file(information1* infor1, score* scor);
void ben_putout_file();//���������뵽excle����
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
void class_management(score* scor, string* arr,string *temp,all_class0*a_c_0);//�༶�����ĺ���
int check_number_file(score* scor, int number);//���ɼ�����ϵͳ���Ƿ��и�ѧ�ŵĺ���
void cout_class(all_class0* a_c_0);
void cout_ave(all_class0* a_c_0);
void cout_abc(int i, int k, score* scor, all_class0* a_c_0);
void judje(int score, int num, int i, all_class0* a_c_0);
void print(all_class0* a_c_0);
int check_class(string clas, all_class0* a_c_0);
void for_information(information1 *infor1,int i,int j);
void for_score(score* scor, int i, int j);