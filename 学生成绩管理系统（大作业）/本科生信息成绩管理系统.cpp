#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define MAX 10000
using namespace std;
/*
ѧ��������Ϣ����ϵͳ
	1.ѧ��������Ϣ���� 
	��1�������������������༶��רҵ���Ա��Զ�����ѧ�� 
	��2���о��������������༶��רҵ���Ա��о����򣬵�ʦ���Զ�����ѧ�� 
	
	2.ѧ��������Ϣ�޸�
	��1���޸ĳ�ѧ���������������
	
	3.ɾ��ѧ����������
	��1������ѧ��ɾ��һ��ѧ��
	
	4.��ѯѧ����������
	��1������ѧ�Ų�ѯѧ���������� 
	
	
�ɼ�����ϵͳ 
	1.����ɼ�
	
	2.����ɼ�
	(1) �ܳɼ��ļ���
	(2) �����ļ���(���ź�У�ţ� 
	(3) �ܳɼ�����(���༶��ѧУ����) 
	
	3.��ѯ�ɼ�
	(1)����ѧ�Ų�ѯѧ�����˳ɼ�
	(2)����(��ҳ)��ʾȫ��ѧ���ɼ�
	(3)���Բ�ѯĳ�༶�в�����ѧ����Ϣ
	 
	4.�޸ĳɼ�
	(1)����ѧ��ѧ�ſ��Զ�ĳ�ſγ̽����޸�
	(2)�޸�ǰ��ʾ��ѧ���ɼ�
	 
	5.ɾ���ɼ�
	(1)����ѧ��ѧ�Ž���ɾ�� 
	
	7.�˳�ϵͳ 
*/
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
};

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
};

void input_information1(information1 *infor1);
void change_information1(information1 *infor1); 
void putout_information1(information1 *infor1);
int check_information1(information1 *infor1); 
void delect_information1(information1 *infor1);
void look_information1(information1 *infor1);

void input_score(score *scor,information1 *infor1);
void cout_ranking(score *scor);
int check_person(score *scor,information1 *infor1);
int check_number(score *scor);
void change_score(score *scor);
void delect_student(score *scor);
void putout_score(score *scor);
void look_score(score *scor);
void class_management(score *scor,string *arr);


int main(){
	struct information1 infor1;
	struct score scor;
	srand((unsigned int)time(NULL));
	string  arr[100];
	
   	ifstream ifs;
   	ifs.open("C:\\Users\\pqy18770657781\\Desktop\\ѧ���ɼ�����ϵͳ.xls",ios::in);
   	char temp;
	while((temp = getline())!=0
	
	
	
	int select1,select2;
	
	while(true)
	{
		cout<<"1.��������Ϣ����ϵͳ"<<endl;
		cout<<"2.�������ɼ�����ϵͳ"<<endl;
		cout<<"3.����Ϣ�ɼ�������"<<endl;
		cout<<"3.�˳�ѧ������ϵͳ"<<endl; 
		cin>>select1;
		system("cls");

		if(select1 == 1)
		{
			while(true)
			{
			cout<<"1.ѧ��������Ϣ���� "<<endl;
			cout<<"2.ѧ��������Ϣ�޸� "<<endl;
			cout<<"3.ɾ��ѧ���������� "<<endl;
			cout<<"4.��ѯѧ���������� "<<endl;
			cout<<"5.���ѧ���������� "<<endl;
			cout<<"6.�˳���Ϣ����ϵͳ "<<endl;
			cin>>select2;
			system("cls");
			if(select2==6)
			{
				break;
			}
			switch(select2)
			{
				case 1:
					input_information1(&infor1);
					break;
				case 2:
					change_information1(&infor1);
					break;
				case 3:
					delect_information1(&infor1);
					break;
				case 4:
					look_information1(&infor1);
					break;
				case 5:
					putout_information1(&infor1);
					break;
			}
			}
		}

		else if(select1 == 2)
		{
			while(true)
		{	
			cout<<"  1.ѧ���ɼ����� "<<endl;
			cout<<"  2.ѧ���ɼ����� "<<endl;
			cout<<"  3.ѧ���ɼ��޸� "<<endl;
			cout<<"  4.ѧ���ɼ�ɾ�� "<<endl;
			cout<<"  5.ѧ���ɼ���ѯ "<<endl;
			cout<<"  6.ѧ���ɼ���� "<<endl;
			cout<<"7.�˳��ɼ�����ϵͳ "<<endl;
			cin>>select2;
			system("cls");
			if(select2==7)
			{
				break;
			}		
			switch(select2)
			{
				case 1:
					input_score(&scor,&infor1);
					break;
				case 2:
					class_management(&scor,arr);
					break;
				case 3:
				{
					change_score(&scor);
					cout_ranking(&scor);
					break;
				}
				case 4:
					delect_student(&scor);
					break;
				case 5:
					look_score(&scor);
					break;
				case 6:
					putout_score(&scor);
					break;								
			}
		}
		}
		
		else if(select1==3)
		{
			ofstream ofs;
			ofs.open("C:\\Users\\pqy18770657781\\Desktop\\ѧ���ɼ�����ϵͳ.xls",ios::app);
			ofs<<"ѧ��\t"<<"����\t"<<"�Ա�\t"<<"�༶\t"<<"רҵ\t"<<"����\t"<<"Ӣ��\t"<<"C����\t"<<"�ܳɼ�\t"<<"������\t"<<"У����\n";
			for(int i=0;i<infor1.size;i++)
			{
				ofs<<infor1.s_i_1[i].student_number<<"\t"
				   <<infor1.s_i_1[i].name<<"\t"
				   <<(infor1.s_i_1[i].sex==1?"��":"Ů")<<"\t"
				   <<infor1.s_i_1[i].clas<<"\t"
				   <<infor1.s_i_1[i].specialty<<"\t"
				   <<scor.s_c[i].high_math<<"\t"
				  <<scor.s_c[i].english<<"\t"
				  <<scor.s_c[i].c_language<<"\t"
				  <<scor.s_c[i].sum_score<<"\t"
				  <<scor.s_c[i].class_ranking<<"\t"
				  <<scor.s_c[i].school_ranking<<"\t"
				  <<endl;
			}
			ofs.close();
			cout<<"����ɹ���"<<endl;
			system("pause");
			system("cls");
		}
		
		
		else if(select1==4)
		{
			system("pause");
			return 0;
		}
	}

}

void input_information1(information1 *infor1)
{
	cout<<"����������:"<<endl;
	string name;
	cin>>name;
	infor1->s_i_1[infor1->size].name = name;
	
	cout<<"�������Ա�:"<<endl;
	cout<<"1-��"<<endl;
	cout<<"2-Ů"<<endl;
	int sex;
	cin>>sex;
	infor1->s_i_1[infor1->size].sex = sex;
	
	cout<<"������༶:"<<endl;
	string clas;
	cin>>clas;
	infor1->s_i_1[infor1->size].clas = clas;
	
	cout<<"������רҵ:"<<endl;
	string specialty;
	cin>>specialty;
	infor1->s_i_1[infor1->size].specialty = specialty;
	
	long int student_number;
	student_number = rand()%10000 + 20200000;
	infor1->s_i_1[infor1->size].student_number = student_number;
	
	infor1->size++;
	
	system("cls");
}

int check_information1(information1 *infor1)
{
	cout<<"������ѧ��ѧ�ţ�"<<endl;
	long int student_number;
	cin>>student_number;
	for(int i=0;i<infor1->size;i++)
	{
		if(infor1->s_i_1[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_information1(information1 *infor1)
{
	int test = check_information1(infor1);
	if(test == -1)
	{
		cout<<"��ѧ�Ų����ڣ�����������"<<endl; 
	}
	
	else
	{
		cout<<"�������޸���Ϣ��"<<endl;
		cout<<"1.����"<<endl;
		cout<<"2.�Ա�"<<endl;
		cout<<"3.�༶"<<endl;
		cout<<"4.רҵ"<<endl;
		
		int select;
		cin>>select;
		switch(select)
		{
			case 1:
				{
				cout<<"����������:"<<endl;
				string name;
				cin>>name;
				infor1->s_i_1[test].name = name;
				break;	
				}
			case 2:
				{
				cout<<"�������Ա�:"<<endl;
				cout<<"1-��"<<endl;
				cout<<"2-Ů"<<endl;
				int sex;
				cin>>sex;
				infor1->s_i_1[test].sex = sex;
				break;
				}
			case 3:
				{
				cout<<"������༶:"<<endl;
				string clas;
				cin>>clas;
				infor1->s_i_1[test].clas = clas;
				break;
				}
			case 4:
				{
				cout<<"������רҵ:"<<endl;
				string specialty;
				cin>>specialty;
				infor1->s_i_1[test].specialty = specialty;
				break;	
				}	
		} 
		cout<<"�޸ĳɹ���"<<endl;
	}
	system("pause");
	system("cls");
}

void delect_information1(information1 *infor1)
{
	int test = check_information1(infor1);
		if(test == -1)
		{
			cout<<"��ѧ�Ų����ڣ�����������"<<endl; 
		}
		
		else
		{
			for(int i=test;i<infor1->size+1;i++)
			{
				infor1->s_i_1[i] = infor1->s_i_1[i+1];
			}
			infor1->size--;
			cout<<"ɾ���ɹ�"<<endl; 
		}
	system("pause");
	system("cls"); 
}

void look_information1(information1 *infor1)
{
	int test = check_information1(infor1);
		if(test == -1)
		{
			cout<<"��ѧ�Ų����ڣ�����������"<<endl; 
		}
		
		else
		{
			cout<<"����:"<<infor1->s_i_1[test].name<<"   "
			<<"�Ա�:"<<(infor1->s_i_1[test].sex==1?"��":"Ů")<<"   "
			<<"�༶:" <<infor1->s_i_1[test].clas<<"   "
			<<"רҵ:"<<infor1->s_i_1[test].specialty<<"   "
			<<"ѧ��:"<<infor1->s_i_1[test].student_number<<endl;
		}
		system("pause");
		system("cls");
}

void putout_information1(information1 *infor1)
{
	for(int i=0;i<infor1->size;i++)
	{
		cout<<"����:"<<infor1->s_i_1[i].name<<"   "
		<<"�Ա�:"<<(infor1->s_i_1[i].sex==1?"��":"Ů")<<"   "
		<<"�༶:" <<infor1->s_i_1[i].clas<<"   "
		<<"רҵ:"<<infor1->s_i_1[i].specialty<<"   "
		<<"ѧ��:"<<infor1->s_i_1[i].student_number<<endl;
	}
	 
	system("pause");
	system("cls");
}

void input_score(score *scor,information1 *infor1)
{
	cout<<"����������:"<<endl;
	string name;
	cin>>name;
	scor->s_c[scor->size].name = name;
	
	int test = check_person(scor,infor1);
		
	if(test == -1)
	{
		cout<<"ѧ����Ϣ����ϵͳ�в��޴��ˣ������Ƿ�������ȷ��"<<endl; 
	}
	
	else
	{
	cout<<"������༶:"<<endl;
	string clas;
	cin>>clas;
	scor->s_c[scor->size].clas = clas;
	
	
	cout<<"�����ɼ���"<<endl;
	int high_math;
	cin>>high_math;
	scor->s_c[scor->size].high_math = high_math;
	
	cout<<"Ӣ��ɼ���"<<endl;
	int english;
	cin>>english;
	scor->s_c[scor->size].english = english;
	
	cout<<"c���Գɼ���"<<endl;
	int c_language;
	cin>>c_language;
	scor->s_c[scor->size].c_language = c_language;	
		
	int sum;
	sum = scor->s_c[scor->size].high_math + scor->s_c[scor->size].english + scor->s_c[scor->size].c_language;
	scor->s_c[scor->size].sum_score = sum;

	scor->size++;
	
	cout_ranking(scor);			
	}
	system("pause");
	system("cls");
}

void cout_ranking(score *scor)
{
	for(int i=0;i<scor->size;i++)
	{
		for(int j=0;j<scor->size;j++)
		{
			if(scor->s_c[j].sum_score<scor->s_c[j+1].sum_score)
			{
				struct student_score temp = scor->s_c[j];
				scor->s_c[j] = scor->s_c[j+1];
				scor->s_c[j+1] = temp;
			}
		}
	}	
	
	for(int k=0;k<scor->size;k++)
	{
		scor->s_c[k].school_ranking = k+1;
	}
}

void putout_score(score *scor)
{
	for(int i=0;i<scor->size;i++)
	{
		cout<<"����:"<<scor->s_c[i].name<<"   "
		<<"ѧ��:"<<scor->s_c[i].student_number<<"   "
		<<"�༶:"<<scor->s_c[i].clas<<"   " 
		<<"����:"<<scor->s_c[i].high_math<<"   "
		<<"Ӣ��:"<<scor->s_c[i].english<<"   "
		<<"c����:"<<scor->s_c[i].c_language<<"   "
		<<"�ܳɼ�"<<scor->s_c[i].sum_score<<"   "
		<<"������"<<scor->s_c[i].class_ranking<<"   " 
		<<"У����:"<<scor->s_c[i].school_ranking<<endl;
	}
	system("pause");
	system("cls");
}

int check_person(score *scor,information1 *infor1)
{
	int num = 0;
	
	for(int i=0;i<infor1->size;i++)
	{
		if(scor->s_c[scor->size].name == infor1->s_i_1[i].name)
		{
			scor->s_c[scor->size].student_number = infor1->s_i_1[i].student_number;
			return 1;
			break;
		}
		
		else{
			num++;
		}
	}
	
	if(num==infor1->size)
	{
		return -1;
	}
	
	return 0;
}

int check_number(score *scor)
{
	cout<<"������ѧ��ѧ�ţ�"<<endl;
	long int student_number;
	cin>>student_number;
	for(int i=0;i<scor->size;i++)
	{
		if(scor->s_c[i].student_number == student_number)
		{
			return i;
		}
	}
	return -1;
}

void change_score(score *scor)
{
	int test = check_number(scor);
	if(test == -1)
	{
		cout<<"��ѧ�Ų����ڣ�����������"<<endl; 
	}
	
	else
	{
		while(true)
		{	
			cout<<"�������޸���Ϣ��"<<endl;
			cout<<"1.����"<<endl;
			cout<<"2.�༶"<<endl;
			cout<<"3.�����ɼ�"<<endl;
			cout<<"4.Ӣ��ɼ�"<<endl;
			cout<<"5.c���Գɼ�"<<endl;
			cout<<"6.�˳��޸�"<<endl;
			
			int select;
			cin>>select;
			if(select==6)
			{
				break;
			}
			
			else
			{
				switch(select)
				{
				case 1:
					{
					cout<<"����������:"<<endl;
					string name;
					cin>>name;
					scor->s_c[test].name = name;
					break;					
					}
				case 2:
					{
					cout<<"������༶:"<<endl;
					string clas;
					cin>>clas;
					scor->s_c[test].clas = clas;	
					break;	
					}
				case 3:
					{
					cout<<"�����ɼ���"<<endl;
					int high_math;
					cin>>high_math;
					scor->s_c[test].high_math = high_math;
					break;		
					}
				case 4:
					{
					cout<<"Ӣ��ɼ���"<<endl;
					int english;
					cin>>english;
					scor->s_c[test].english = english;
					break;		
					}
				case 5:
					{
					cout<<"c���Գɼ���"<<endl;
					int c_language;
					cin>>c_language;
					scor->s_c[test].c_language = c_language;		
					}
				}
			system("cls");
			}
		}
	cout<<"�޸ĳɹ�"<<endl;	
	int sum;
	sum = scor->s_c[test].high_math + scor->s_c[test].english + scor->s_c[test].c_language;
	scor->s_c[test].sum_score = sum;
	
	cout_ranking(scor);
	}
	system("pause");
	system("cls");
}

void delect_student(score *scor)
{
	int test = check_number(scor);
	if(test == -1)
	{
		cout<<"��ѧ�Ų����ڣ�����������"<<endl; 
	}
			
	else
	{
		for(int i=test;i<scor->size+1;i++)
		{
			scor->s_c[i] = scor->s_c[i+1];
		}
		scor->size--;
		cout<<"ɾ���ɹ�"<<endl; 
	}
	cout_ranking(scor);
	system("pause");
	system("cls"); 
}

void look_score(score *scor)
{
	int test = check_number(scor);
	if(test == -1)
	{
		cout<<"��ѧ�Ų����ڣ�����������"<<endl; 
	}
	
	else{
	cout<<"����:"<<scor->s_c[test].name<<"   "
	<<"ѧ��:"<<scor->s_c[test].student_number<<"   "
	<<"�༶:"<<scor->s_c[test].clas<<"   " 
	<<"����:"<<scor->s_c[test].high_math<<"   "
	<<"Ӣ��:"<<scor->s_c[test].english<<"   "
	<<"c����:"<<scor->s_c[test].c_language<<"   "
	<<"�ܳɼ�"<<scor->s_c[test].sum_score<<"   "
	<<"У����:"<<scor->s_c[test].school_ranking<<endl;		
	}
	system("pause");
	system("cls");
}

void class_management(score *scor,string *arr)
{
	for(int i=0;i<scor->size;i++)
	{
		arr[i] = scor->s_c[i].clas;
	}
		
	string temp[100];
	int m = 0;
	for(int j=0;j<100;j++)
	{
		int k = 0;
		for(;k<m;k++)
		{
			if(arr[j]==temp[k])
			{
				break;
			}
		}
			
		if(k == m)
		{
			temp[m] = arr[j];
			m++;
		}
	}
	
	for(int i=0;i<100;i++)
	{
		int k=0;
		for(int j=0;j<100;j++)
		{
			for(;k<scor->size;k++)
			{
				if(scor->s_c[k].clas != " ")
				{
					if(scor->s_c[k].clas == temp[i])
					{
						scor->s_c[k].class_ranking = j+1;
						k = k+1;
						break;
					}		
				}
			}
		}
	} 
	cout<<"�������"<<endl;
	system("pause");
	system("cls");
}
