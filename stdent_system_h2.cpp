#include "student_system_t2.h"

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
	int school_ranking = 0;
	long int student_number = 0;
};

struct score2
{
	student_score2 s_c_2[MAX];
	int size = 0;
}scor2;

int yan_student_system()
{
	int select1, select2;

	while (true)
	{
		cout << "1.�о�����Ϣ����ϵͳ" << endl;
		cout << "2.�о����ɼ�����ϵͳ" << endl;
		cout << "3.����Ϣ�ɼ�������" << endl;
		cout << "4.�˳�ѧ������ϵͳ" << endl;
		cin >> select1;
		system("cls");

		if (select1 == 1)
		{
			while (true)
			{
				cout << "1.ѧ��������Ϣ���� " << endl;
				cout << "2.ѧ��������Ϣ�޸� " << endl;
				cout << "3.ɾ��ѧ���������� " << endl;
				cout << "4.��ѯѧ���������� " << endl;
				cout << "5.���ѧ���������� " << endl;
				cout << "6.�˳���Ϣ����ϵͳ " << endl;
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
					//ѧ��������Ϣ����
					break;
				case 2:
					change_information2(&infor2);
					//ѧ��������Ϣ�޸�
					break;
				case 3:
					delect_information2(&infor2);
					//ɾ��ѧ����������
					break;
				case 4:
					look_information2(&infor2);
					//��ѯѧ����������
					break;
				case 5:
					putout_information2(&infor2);
					//���ѧ����������
					break;
				}
			}
		}

		else if (select1 == 2)
		{
			while (true)
			{
				cout << "  1.ѧ���ɼ����� " << endl;
				cout << "  2.ѧ���ɼ����� " << endl;
				cout << "  3.ѧ���ɼ��޸� " << endl;
				cout << "  4.ѧ���ɼ�ɾ�� " << endl;
				cout << "  5.ѧ���ɼ���ѯ " << endl;
				cout << "  6.ѧ���ɼ���� " << endl;
				cout << "7.�˳��ɼ�����ϵͳ " << endl;
				cin >> select2;
				system("cls");
				if (select2 == 7)
				{
					break;
				}
				switch (select2)
				{
				case 1:
					//ѧ���ɼ�����
					break;
				case 2:
					//ѧ���ɼ�����
					break;
				case 3:
				{
					//ѧ���ɼ��޸�
					break;
				}
				case 4:
					//ѧ���ɼ�ɾ��
					break;
				case 5:
					//ѧ���ɼ���ѯ
					break;
				case 6:
					//ѧ���ɼ����
					break;
				}
			}
		}

		else if (select1 == 3)
		{
			//�ļ�������excl����
		}


		else if (select1 == 4)
		{
			//�˳��о���ϵͳ
			system("pause");
			return 0;
		}
	}
}

void input_information2(information2* infor2)
{
	cout << "����������:" << endl;
	string name;
	cin >> name;
	infor2->s_i_2[infor2->size].name = name;

	cout << "�������Ա�:" << endl;
	cout << "1-��" << endl;
	cout << "2-Ů" << endl;
	int sex;
	cin >> sex;
	infor2->s_i_2[infor2->size].sex = sex;

	cout << "������༶:" << endl;
	string clas;
	cin >> clas;
	infor2->s_i_2[infor2->size].clas = clas;

	cout << "������רҵ:" << endl;
	string specialty;
	cin >> specialty;
	infor2->s_i_2[infor2->size].specialty = specialty;

	cout << "�������о�����" << endl;
	string research_direction;
	cin >> research_direction;
	infor2->s_i_2[infor2->size].research_direction = research_direction;

	cout << "�����뵼ʦ������" << endl;
	string tutor;
	cin >> tutor;
	infor2->s_i_2[infor2->size].tutor = tutor;

	long int student_number;
	student_number = rand() % 10000 + 20190000;
	infor2->s_i_2[infor2->size].student_number = student_number;

	infor2->size++;

	system("cls");
}

void putout_information2(information2* infor2)
{
	for (int i = 0; i < infor2->size; i++)
	{
		cout << "����:" << infor2->s_i_2[i].name << "   "
			<< "�Ա�:" << (infor2->s_i_2[i].sex == 1 ? "��" : "Ů") << "   "
			<< "�༶:" << infor2->s_i_2[i].clas << "   "
			<< "רҵ:" << infor2->s_i_2[i].specialty << "   "
			<< "�о�����:" << infor2->s_i_2[i].research_direction << "   "
			<< "��ʦ:" << infor2->s_i_2[i].tutor << "   "
			<< "ѧ��:" << infor2->s_i_2[i].student_number << endl;
	}

	system("pause");
	system("cls");
}

int check_information2(information2* infor2)
{
	cout << "������ѧ��ѧ�ţ�" << endl;
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
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		cout << "�������޸���Ϣ��" << endl;
		cout << "1.����" << endl;
		cout << "2.�Ա�" << endl;
		cout << "3.�༶" << endl;
		cout << "4.רҵ" << endl;
		cout << "5.�о�����" << endl;
		cout << "6.��ʦ" << endl;

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "����������:" << endl;
			string name;
			cin >> name;
			infor2->s_i_2[test].name = name;
			break;
		}
		case 2:
		{
			cout << "�������Ա�:" << endl;
			cout << "1-��" << endl;
			cout << "2-Ů" << endl;
			int sex;
			cin >> sex;
			infor2->s_i_2[test].sex = sex;
			break;
		}
		case 3:
		{
			cout << "������༶:" << endl;
			string clas;
			cin >> clas;
			infor2->s_i_2[test].clas = clas;
			break;
		}
		case 4:
		{
			cout << "������רҵ:" << endl;
			string specialty;
			cin >> specialty;
			infor2->s_i_2[test].specialty = specialty;
			break;
		}
		case 5:
		{
			cout << "�������о�����" << endl;
			string research_direction;
			cin >> research_direction;
			infor2->s_i_2[test].research_direction = research_direction;
			break;
		}
		case 6:
		{
			cout << "�����뵼ʦ������" << endl;
			string tutor;
			cin >> tutor;
			infor2->s_i_2[test].tutor = tutor;
			break;
		}
		}
		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void delect_information2(information2* infor2)
{
	int test = check_information2(infor2);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		for (int i = test; i < infor2->size + 1; i++)
		{
			infor2->s_i_2[i] = infor2->s_i_2[i + 1];
		}
		infor2->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void look_information2(information2* infor2)
{
	int test = check_information2(infor2);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		cout << "����:" << infor2->s_i_2[test].name << "   "
			<< "�Ա�:" << (infor2->s_i_2[test].sex == 1 ? "��" : "Ů") << "   "
			<< "�༶:" << infor2->s_i_2[test].clas << "   "
			<< "רҵ:" << infor2->s_i_2[test].specialty << "   "
			<< "�о�����:" << infor2->s_i_2[test].research_direction << "   "
			<< "��ʦ:" << infor2->s_i_2[test].tutor << "   "
			<< "ѧ��:" << infor2->s_i_2[test].student_number << endl;
	}
	system("pause");
	system("cls");
}