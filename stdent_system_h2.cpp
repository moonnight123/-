#include "student_system_t2.h"

struct student_information2
{
	string name = " ";//����
	int sex = 0;;//�Ա�
	string clas = " ";//�༶
	string specialty = " ";//רҵ
	string research_direction = " ";//�о�����
	string tutor = " ";//��ʦ
	long int student_number = 0;//ѧ��
};

struct information2
{
	student_information2 s_i_2[MAX];
	int size = 0;//��¼ѧ������
}infor2;

struct student_score2
{
	string name = " ";//����
	string clas = " ";//�༶
	int all_class_score = 0;//�γ��ܳɼ�
	int thesis = 0;//���ĳɼ�
	int sum_score = 0;//�ܳɼ�
	int class_ranking = 0;//�༶����
	int school_ranking = 0;//ѧУ����
	long int student_number = 0;//ѧ��
};

struct score2
{
	student_score2 s_c_2[MAX];
	int size = 0;
}scor2;

int yan_student_system()
{
	int select1;

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
			yan_student_information_system();//�о�����Ϣ����ϵͳ
		}

		else if (select1 == 2)
		{
			yan_student_score_system();//�о����ɼ�����ϵͳ
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

void yan_student_information_system()
{
	int select2;
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

void yan_student_score_system()
{
	int select2;
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
			input_score(&scor2, &infor2);
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

	//���������ѧ��
	long int student_number;
	student_number = rand() % 10000 + 20190000;
	infor2->s_i_2[infor2->size].student_number = student_number;

	//
	infor2->size++;

	system("cls");
}

void putout_information2(information2* infor2)
{
	for (int i = 0; i < infor2->size; i++)
	{
		//����ɼ�
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
	//�жϸ�ѧ��ѧ���Ƿ����
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
		//ɾ��ѧ����Ϣ
		//ͨ������һλѧ������Ϣ����ǰһλѧ������Ϣ�ķ���ʵ��ѧ����Ϣ��ɾ��
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
		//������Ϣ���
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

int check_person(score2* scor2, information2* infor2)
{
	int num = 0;

	//�ж�ѧ����Ϣϵͳ���Ƿ���ڸ�ѧ������

	for (int i = 0; i < infor2->size; i++)
	{
		if (scor2->s_c_2[scor2->size].name == infor2->s_i_2[i].name)
		{
			scor2->s_c_2[scor2->size].student_number = infor2->s_i_2[i].student_number;
			return 1;
			break;
		}

		else {
			num++;
		}
	}

	if (num == infor2->size)
	{
		return -1;
	}

	return 0;
}

void input_score(score2* scor2, information2* infor2)
{
	cout << "����������:" << endl;
	string name;
	cin >> name;
	scor2->s_c_2[scor2->size].name = name;

	int test = check_person(scor2, infor2);

	if (test == -1)
	{
		cout << "ѧ����Ϣ����ϵͳ�в��޴��ˣ������Ƿ�������ȷ��" << endl;
	}

	else
	{
		cout << "������༶:" << endl;
		string clas;
		cin >> clas;
		scor2->s_c_2[scor2->size].clas = clas;


		cout << "�γ��ܳɼ��ɼ���" << endl;
		int all_class_score;
		cin >> all_class_score;
		scor2->s_c_2[scor2->size].all_class_score = all_class_score;

		cout << "���ĳɼ���" << endl;
		int thesis;
		cin >> thesis;
		scor2->s_c_2[scor2->size].thesis = thesis;

		//�����ܳɼ�
		int sum;
		sum = scor2->s_c_2[scor2->size].thesis + scor2->s_c_2[scor2->size].all_class_score;
		scor2->s_c_2[scor2->size].sum_score = sum;

		scor2->size++;

		cout_ranking(scor2);//��������
	}
	system("pause");
	system("cls");
}

void cout_ranking(score2* scor2)
{
	for (int i = 0; i < scor2->size; i++)
	{
		for (int j = 0; j < scor2->size; j++)
		{
			//ͨ��ð�������ѧ���ܳɼ���������
			if (scor2->s_c_2[j].sum_score < scor2->s_c_2[j + 1].sum_score)
			{
				//�Ա��ܳɼ�������ѧ���Ľṹ�����
				struct student_score2 temp = scor2->s_c_2[j];
				scor2->s_c_2[j] = scor2->s_c_2[j + 1];
				scor2->s_c_2[j + 1] = temp;
			}
		}
	}

	for (int k = 0; k < scor2->size; k++)
	{
		scor2->s_c_2[k].school_ranking = k + 1;
	}
}