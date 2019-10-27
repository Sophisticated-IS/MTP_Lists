#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;

struct List
{
	int d;
	List* next; // - ��������� �� ��������� �����
};
//typedef n *PN;// ������� ��� PN, ����������� ���� ��������� n
List* init_List()//�������� ������� ��-��
{
	List* one;//������ ��-�� ������
	one = new (List);
	(*one).d = 0;//���-�� ��-�� = 0 
	(*one).next = NULL;
	
	return one;//��������� ��������
	delete(one);// ���������� ������
}

void insert_elt (List* &last_elt,int new_elt)//���������� ����� ������  ?? ������ ����� ����� ������
{
	List* elem;
	elem = new (List);
	(*elem).next = NULL;//�� ������ �������� ��� ������
	(*elem).d = new_elt;//���������������� ��� ���� ������ ��-�� 

	(*last_elt).next = elem;//������ ��������� ���������� ��-�� ������, ����� �� �������� �� ����� ���������
	last_elt = elem;//����������� ��������� ����� �� �������� ����� �� ����� ��������� ��-��
	
}

void del_List(List* &head)//��������� �� ������ ������ ?? ����������� ������ �����-�� �����(���������)
{
	delete(head);
}
void null_List(List* &head)//�������� NULL head
{
	head = NULL;
}
void del_List_clr_all_elts (List* &head)
{
	
	while (head!=NULL)
	{
		List* tmp;
		tmp = head;//��-�� ������� ���������
		(*tmp).d = rand();//��������� ������ ������ (������-��)
		head = (*head).next;//��������� �� ��������� ��-�� ����� ������
		//delete(tmp);//������� ��������� ??�� ���� ���� � ���� ���������� - !!�� ������-�� ���������� ������� ������ �������������
		tmp = NULL;
	}
}
int average_ariphmetics(List* head)
{
	int sum=0;
	List* i;//��������� ��� �����-�� �� ������
	
	if ((*head).d > 0)//���� ���� ���� ���� ��-��, � �� ������ ������
	for (i = (*head).next; i != NULL; i = (*i).next)//���������� �� ������� ��-�� 1-�� - head
		sum += (*i).d;
	
	if ((*head).d > 0)
	{
		return sum / (*head).d;
	}
	else
		return 0;
	
}
void print_List(List* head)
{
	cout << endl;
	List* i;//��������� ��� �����-�� �� ������
	i = head;
	if (i == NULL)
	{
		cout << "������ ���˨�((((((" << endl;
	}
	else
	{
	  for (; i != NULL; i = (*i).next)
		cout << "��� ���� t1= " << i << " ���� ���� D=" << (*i).d << " ���� ���� next=" << (*i).next << endl;
	    cout<< endl;
	}
	
}
void del_1n2_elts(List* &head)
{
	if ((*head).d >= 2)
	{
		List* del_el;//����-�� ��-��

		for (int i = 0; i < 2; i++)
		{

			del_el = (*head).next;
			(*head).next = (*del_el).next;//������������ ������ � ��-�� ����� ����������
			(*head).d --;
			//����� ��-�� ��� ������ ��������
			print_List(head);
		}
		
	}
}
int main(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	int list_siz;
	cout << "������� ���-�� ��-�� ������: "; cin >> list_siz; cout << endl;
	
	//****************************** ������������� *********************************
	
	List* head = init_List();//������������� ���-�� 
	
	 //****************************** ������� ��-�� � ������ *********************************
	
	List* ins_pointer = head;//������� ��������� ������� ������������� �� 1-�� ��-��
	int inp_elt;//��-�� ��� ������� 
	for (int i = 0; i < list_siz; i++)
	{
		cout << "������� ��������� ��-�� ������: ";
		cin >> inp_elt;
		insert_elt(ins_pointer, inp_elt);
		//ins_pointer = (*ins_pointer).next;
		head->d++;//����������� ������� ��-�� ������
		print_List(head);
		cout << endl;
	}
	//delete(ins_pointer);//����-�� ����-�� ����� �������	��� ������ ������ ���
	//**********��� ���������:
	ins_pointer = NULL;//������ ������� ��������� �� ������� � NULL ����� ��� ������� ��-��
	free(ins_pointer);

	//****************************** ������� �����-�� ��-�� ������ *********************************
	cout<<"������� �����-�� ��� �� - �� ������ = "<<average_ariphmetics(head)<<endl;
	cout << endl;
	//***************************** �������� ������ ���� ��-�� *****************************
	cout << "�������� ������� � ������� ��-�� (���� ��������):" << endl;
	del_1n2_elts(head);
	//****************************** �������� ������ *********************************
	cout << "�������� ����� ������:" << endl;
	//del_List(head);// �����-�� ������ ������ ��������� �� ������
	//***** 1 ������� ���� ��NULL ������ � �� *****
	/*null_List(head);
	print_List(head);*/
	// 2 ������� ������ ���. ���� � ��� ��������� ��������
	del_List_clr_all_elts(head);
	print_List(head);
	
	system("pause");
	return 0;
}


