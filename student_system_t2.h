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

int yan_student_system();//�о�������ϵͳ
void yan_student_information_system();//�о�����Ϣ����ϵͳ
void yan_student_score_system();//�о����ɼ�����ϵͳ 
void input_information2(information2* infor2);//��Ϣ����ĺ���
void putout_information2(information2* infor2);//��Ϣ�������
int check_information2(information2* infor2);//��ѯѧ�ŵĺ���
void change_information2(information2* infor2);//�޸���Ϣ�ĺ���
void delect_information2(information2* infor2);//ɾ����Ϣ�ĺ���
void look_information2(information2* infor2);//��ѯ������Ϣ�ĺ���

int check_person(score2* scor2, information2* infor2);//�жϲ�ѯ��Ϣϵͳ���Ƿ�������ѧ�������ĺ���
void input_score(score2* scor2, information2* infor2);//�ɼ�����ĺ���
void cout_ranking(score2* scor2);//����ѧУ�������ĺ���