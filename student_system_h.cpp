#include "student_system_t.h"

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
					//ѧ��������Ϣ�޸�
					break;
				case 3:
					//ɾ��ѧ����������
					break;
				case 4:
					//��ѯѧ����������
					break;
				case 5:
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
					//ѧ��������Ϣ�޸�
					break;
				case 3:
					//ɾ��ѧ����������
					break;
				case 4:
					//��ѯѧ����������
					break;
				case 5:
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