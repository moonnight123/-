#include "student_system_t.h"


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

int ben_student_system()
{
	int select1, select2;

	while (true)
	{
		cout << "1.��������Ϣ����ϵͳ" << endl;
		cout << "2.�������ɼ�����ϵͳ" << endl;
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
					input_information1(&infor1);
					//����ѧ����Ϣ
					break;
				case 2:
					change_information1(&infor1);
					//ѧ��������Ϣ�޸�
					break;
				case 3:
					delect_information1(&infor1);
					//ɾ��ѧ����������
					break;
				case 4:
					look_information1(&infor1);
					//��ѯѧ����������
					break;
				case 5:
					putout_information1(&infor1);
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
			//�˳�������ϵͳ
			system("pause");
			return 0;
		}
	}

}

void input_information1(information1* infor1)
{
	cout << "����������:" << endl;
	string name;
	cin >> name;
	infor1->s_i_1[infor1->size].name = name;

	cout << "�������Ա�:" << endl;
	cout << "1-��" << endl;
	cout << "2-Ů" << endl;
	int sex;
	cin >> sex;
	infor1->s_i_1[infor1->size].sex = sex;

	cout << "������༶:" << endl;
	string clas;
	cin >> clas;
	infor1->s_i_1[infor1->size].clas = clas;

	cout << "������רҵ:" << endl;
	string specialty;
	cin >> specialty;
	infor1->s_i_1[infor1->size].specialty = specialty;

	long int student_number;
	student_number = rand() % 10000 + 20200000;
	infor1->s_i_1[infor1->size].student_number = student_number;

	infor1->size++;

	system("cls");
}

void putout_information1(information1* infor1)
{
	for (int i = 0; i < infor1->size; i++)
	{
		cout << "����:" << infor1->s_i_1[i].name << "   "
			<< "�Ա�:" << (infor1->s_i_1[i].sex == 1 ? "��" : "Ů") << "   "
			<< "�༶:" << infor1->s_i_1[i].clas << "   "
			<< "רҵ:" << infor1->s_i_1[i].specialty << "   "
			<< "ѧ��:" << infor1->s_i_1[i].student_number << endl;
	}

	system("pause");
	system("cls");
}

int check_information1(information1* infor1)
{
	cout << "������ѧ��ѧ�ţ�" << endl;
	long int student_number;
	cin >> student_number;
	for (int i = 0; i < infor1->size; i++)
	{
		if (infor1->s_i_1[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_information1(information1* infor1)
{
	int test = check_information1(infor1);
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

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "����������:" << endl;
			string name;
			cin >> name;
			infor1->s_i_1[test].name = name;
			break;
		}
		case 2:
		{
			cout << "�������Ա�:" << endl;
			cout << "1-��" << endl;
			cout << "2-Ů" << endl;
			int sex;
			cin >> sex;
			infor1->s_i_1[test].sex = sex;
			break;
		}
		case 3:
		{
			cout << "������༶:" << endl;
			string clas;
			cin >> clas;
			infor1->s_i_1[test].clas = clas;
			break;
		}
		case 4:
		{
			cout << "������רҵ:" << endl;
			string specialty;
			cin >> specialty;
			infor1->s_i_1[test].specialty = specialty;
			break;
		}
		}
		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void delect_information1(information1* infor1)
{
	int test = check_information1(infor1);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		for (int i = test; i < infor1->size + 1; i++)
		{
			infor1->s_i_1[i] = infor1->s_i_1[i + 1];
		}
		infor1->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void look_information1(information1* infor1)
{
	int test = check_information1(infor1);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		cout << "����:" << infor1->s_i_1[test].name << "   "
			<< "�Ա�:" << (infor1->s_i_1[test].sex == 1 ? "��" : "Ů") << "   "
			<< "�༶:" << infor1->s_i_1[test].clas << "   "
			<< "רҵ:" << infor1->s_i_1[test].specialty << "   "
			<< "ѧ��:" << infor1->s_i_1[test].student_number << endl;
	}
	system("pause");
	system("cls");
}