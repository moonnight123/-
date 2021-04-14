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

	yan_putin_file(&infor2, &scor2);

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
			yan_putout_file();
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
	string  arr[100];

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
			class_management(&scor2, arr);
			//ѧ���ɼ�����
			break;
		case 3:
		{
			change_score(&scor2);
			//ѧ���ɼ��޸�
			break;
		}
		case 4:
			delect_student(&scor2);
			//ѧ���ɼ�ɾ��
			break;
		case 5:
			look_score(&scor2);
			//ѧ���ɼ���ѯ
			break;
		case 6:
			putout_score(&scor2);
			//ѧ���ɼ����
			break;
		}
	}
}

void yan_putout_file()
{
	ofstream ofs;
	ofs.open("C:\\Users\\pqy18770657781\\Desktop\\vs2019\\student score system\\student score system\\�о����ɼ�����ϵͳ.xls", ios::out);
	ofs << "ѧ��\t" << "����\t" << "�Ա�\t" << "�༶\t" << "רҵ\t" << "�о�����\t" << "��ʦ\t" << "�γ��ܳɼ�\t" << "���ĳɼ�\t" << "�ܳɼ�\t" << "������\t" << "У����\n";
	for (int i = 0; i < infor2.size; i++)
	{
		ofs << infor2.s_i_2[i].student_number << "\t"
			<< infor2.s_i_2[i].name << "\t"
			<< (infor2.s_i_2[i].sex == 1 ? "��" : "Ů") << "\t"
			<< infor2.s_i_2[i].clas << "\t"
			<< infor2.s_i_2[i].specialty << "\t"
			<< infor2.s_i_2[i].research_direction << "\t"
			<< infor2.s_i_2[i].tutor << "\t";

		int number = infor2.s_i_2[i].student_number;
		int test = check_number_file(&scor2, number);
		if (test == -1)
		{
			ofs << endl;
		}

		else {
			ofs<< scor2.s_c_2[test].all_class_score << "\t"
			<< scor2.s_c_2[test].thesis << "\t"
			<< scor2.s_c_2[test].sum_score << "\t"
			<< scor2.s_c_2[test].class_ranking << "\t"
			<< scor2.s_c_2[test].school_ranking << "\t"
			<< endl;
		}
		  
	}
	ofs.close();
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
}

void yan_putin_file(information2* infor2, score2* scor2)
{
	ifstream ifs;
	ifs.open("C:\\Users\\pqy18770657781\\Desktop\\vs2019\\student score system\\student score system\\�о����ɼ�����ϵͳ.xls", ios::in);
	char buf[1024] = { 0 };
	for (int i = 0; i < 12; i++)
	{
		ifs >> buf;
	}


	while (ifs >> buf)
	{
		for (int i = 1; i < 13; i++)
		{
			if (i == 1)
			{
				long int student_number = 0;
				student_number = atol(buf);
				infor2->s_i_2[infor2->size].student_number = student_number;
				scor2->s_c_2[scor2->size].student_number = student_number;
				ifs >> buf;
			}

			else if (i == 2)
			{
				infor2->s_i_2[infor2->size].name = buf;
				scor2->s_c_2[scor2->size].name = buf;
				ifs >> buf;
			}

			else if (i == 3)
			{
				int sex = 0;
				if (buf ==(string) "��")
				{
					sex = 1;
				}

				else if(buf == (string)"Ů")
				{
					sex = 2;
				}

				infor2->s_i_2[infor2->size].sex = sex;
				ifs >> buf;
			}

			else if (i == 4)
			{
				infor2->s_i_2[infor2->size].clas = buf;
				scor2->s_c_2[scor2->size].clas = buf;
				ifs >> buf;
			}

			else if (i == 5)
			{
				infor2->s_i_2[infor2->size].specialty = buf;
				ifs >> buf;
			}

			else if (i == 6)
			{
				infor2->s_i_2[infor2->size].research_direction = buf;
				ifs >> buf;
			}

			else if (i == 7)
			{
				infor2->s_i_2[infor2->size].tutor = buf;
				ifs >> buf;
			}

			else if (i == 8)
			{
				int all_class_score = 0;
				all_class_score = atoi(buf);
				scor2->s_c_2[scor2->size].all_class_score= all_class_score;
				ifs >> buf;
			}

			else if (i == 9)
			{
				int thesis = 0;
				thesis = atoi(buf);
				scor2->s_c_2[scor2->size].thesis = thesis;
				ifs >> buf;
			}

			else if (i == 10)
			{
				int sum_score = 0;
				sum_score = atoi(buf);
				scor2->s_c_2[scor2->size].sum_score= sum_score;
				ifs >> buf;
			}

			else if (i == 11)
			{
				int class_ranking = 0;
				class_ranking = atoi(buf);
				scor2->s_c_2[scor2->size].class_ranking = class_ranking;
				ifs >> buf;
			}

			else if (i == 12)
			{
				int school_ranking = 0;
				school_ranking = atoi(buf);
				scor2->s_c_2[scor2->size].school_ranking = school_ranking;
			}
		}

		infor2->size++;
		scor2->size++;
	}

	ifs.close();
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

int check_number(score2* scor2)
{
	//��ѯѧ��ѧ��
	cout << "������ѧ��ѧ�ţ�" << endl;
	long int student_number;
	cin >> student_number;
	for (int i = 0; i < scor2->size; i++)
	{
		//�鵽ѧ��ѧ�ţ�����ѧ���ڽṹ���еĵ�ѧ��
		if (scor2->s_c_2[i].student_number == student_number)
		{
			return i;
		}
	}
	//û�鵽�򷵻�-1
	return -1;
}

void change_score(score2* scor2)
{
	int test = check_number(scor2);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		while (true)
		{
			cout << "�������޸���Ϣ��" << endl;
			cout << "1.����" << endl;
			cout << "2.�༶" << endl;
			cout << "3.�γ��ܳɼ��ɼ�" << endl;
			cout << "4.���ĳɼ�" << endl;
			cout << "6.�˳��޸�" << endl;

			int select;
			cin >> select;
			if (select == 6)
			{
				break;
			}

			else
			{
				switch (select)
				{
				case 1:
				{
					cout << "����������:" << endl;
					string name;
					cin >> name;
					scor2->s_c_2[test].name = name;
					break;
				}
				case 2:
				{
					cout << "������༶:" << endl;
					string clas;
					cin >> clas;
					scor2->s_c_2[test].clas = clas;
					break;
				}
				case 3:
				{
					cout << "�γ��ܳɼ��ɼ���" << endl;
					int all_class_score;
					cin >> all_class_score;
					scor2->s_c_2[test].all_class_score = all_class_score;
					break;
				}
				case 4:
				{
					cout << "���ĳɼ���" << endl;
					int thesis;
					cin >> thesis;
					scor2->s_c_2[test].thesis = thesis;
					break;
				}
				}
				system("cls");
			}
		}
		cout << "�޸ĳɹ�" << endl;

		//���¼����ܳɼ��Լ�������
		int sum;
		sum = scor2->s_c_2[test].all_class_score + scor2->s_c_2[test].thesis;
		scor2->s_c_2[test].sum_score = sum;

		cout_ranking(scor2);
	}
	system("pause");
	system("cls");
}

void delect_student(score2* scor2)
{
	int test = check_number(scor2);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else
	{
		//ͨ������һλѧ������Ϣ�ɼ�ǰһλѧ������Ϣ�ķ���ʵ��ѧ���ɼ���ɾ��
		for (int i = test; i < scor2->size + 1; i++)
		{
			scor2->s_c_2[i] = scor2->s_c_2[i + 1];
		}
		scor2->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	cout_ranking(scor2);
	system("pause");
	system("cls");
}

void look_score(score2* scor2)
{
	int test = check_number(scor2);
	if (test == -1)
	{
		cout << "��ѧ�Ų����ڣ�����������" << endl;
	}

	else {
		cout << "����:" << scor2->s_c_2[test].name << "   "
			<< "ѧ��:" << scor2->s_c_2[test].student_number << "   "
			<< "�༶:" << scor2->s_c_2[test].clas << "   "
			<< "�γ��ܳɼ�:" << scor2->s_c_2[test].all_class_score << "   "
			<< "���ĳɼ�:" << scor2->s_c_2[test].thesis << "   "
			<< "�ܳɼ�" << scor2->s_c_2[test].sum_score << "   "
			<< "У����:" << scor2->s_c_2[test].school_ranking << endl;
	}
	system("pause");
	system("cls");
}

void putout_score(score2* scor2)
{
	for (int i = 0; i < scor2->size; i++)
	{
		cout << "����:" << scor2->s_c_2[i].name << "   "
			<< "ѧ��:" << scor2->s_c_2[i].student_number << "   "
			<< "�༶:" << scor2->s_c_2[i].clas << "   "
			<< "�γ��ܳɼ�:" << scor2->s_c_2[i].all_class_score << "   "
			<< "���ĳɼ�:" << scor2->s_c_2[i].thesis << "   "
			<< "�ܳɼ�" << scor2->s_c_2[i].sum_score << "   "
			<< "������" << scor2->s_c_2[i].class_ranking << "   "
			<< "У����:" << scor2->s_c_2[i].school_ranking << endl;
	}
	system("pause");
	system("cls");
}

void class_management(score2* scor2, string* arr)
{
	//�Ƚ�ÿ��ѧ���İ༶���뵽һ���������ٽ��в���ȥ���ظ��İ༶
	for (int i = 0; i < scor2->size; i++)
	{
		arr[i] = scor2->s_c_2[i].clas;
	}

	string temp[100];
	int m = 0;
	for (int j = 0; j < 100; j++)
	{
		int k = 0;
		for (; k < m; k++)
		{
			if (arr[j] == temp[k])
			{
				break;
			}
		}

		if (k == m)
		{
			temp[m] = arr[j];
			m++;
		}
	}

//�����Ѿ��ź��ܳɼ���ѧ������ÿ��ѧ���ֵ���Ӧ�İ༶�У�����ÿ��ѧ������༶�Ĵ�������������
	//i���������еİ༶��ţ��ӽṹ���б���ѧ�������İ༶�����Ϊi�İ༶���жԱ�
	for (int i = 0; i < 100; i++)
	{
		//j����༶�е��������ӽṹ����ѡ�з���i����İ༶��ѧ�����ӵ�һ����ʼ��������
		int k = 0;
		for (int j = 0; j < 100; j++)
		{
			//k����ṹ����ѧ������ţ��ӽṹ����Ѱ�ҷ�������������ѧ��������ӵ�k����ҵ���Ϊ�丳���������ٴ�k+1��ż���Ѱ�ң�ֱ������������ѧ��
			for (; k < scor2->size; k++)
			{
				//�༶�����ܵ��ǿյ�
				if (scor2->s_c_2[k].clas != " ")
				{
					//������ѧ���༶Ҫ��༶�����е�i���༶������һ��
					if (scor2->s_c_2[k].clas == temp[i])
					{
						scor2->s_c_2[k].class_ranking = j + 1;
						k = k + 1;
						break;
					}
				}
			}
		}
	}
	cout << "�������" << endl;
	system("pause");
	system("cls");
}

int check_number_file(score2* scor2, int number)
{
	for (int i = 0; i < scor2->size; i++)
	{
		if (scor2->s_c_2[i].student_number == number)
		{
			return i;
		}
	}
	return -1;
}