#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;

struct n
{
	int d;
	n* next; // - ��������� �� ��������� �����
};
//typedef n *PN;// ������� ��� PN, ����������� ���� ��������� n


int main(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	int list_siz;
	cout << "������� ���-�� ��-�� ������: "; cin >> list_siz; cout << endl;

	n* one;//������ ��-�� ������
	n* t;
	//------------�������� ���� ������
	t = new (n);
	(*t).next = NULL;
	(*t).d = list_siz;//�������� ������ ������

	one = t;
    n* t1;//������������ ������ ��� ������ ������
	
	int elem_list = 0;
	for (int i = 0; i < list_siz; i++)
	{
		cout << "������� ��������� ��-�� ������: "; cin >> elem_list; cout << endl;
		//**************������� � ����� ������*****************************
		n* elem;
		elem = new (n);
		(*elem).next = NULL;//�� ������ �������� ��� ������
		(*elem).d = elem_list;//���������������� ��� ���� ������ ��-�� 

		(*t).next = elem;
		t = (*t).next;
//*****************************************����� ������ ����� �������*******************
		for (t1 = one; t1 != NULL; t1 = (*t1).next)
			cout << "��� ���� t1= " << t1 << " ���� ���� D=" << (*t1).d << " ���� ���� next=" << (*t1).next << endl;
		cout << endl;
	}
	cout << endl;
	
	/*for (t1 = one; t1 != NULL; t1 = (*t1).next)
		cout << "��� ���� t1= " << t1 << " ���� ���� D=" << (*t1).d << " ���� ���� next=" << (*t1).next << endl;
	cout << endl;*/

	//*************************������� �����-��************************************
	int summ = 0;
	for (t1 = (*one).next; t1 != NULL; t1 = (*t1).next)//�� �����-��
		summ += (*t1).d;
	cout << "������� �������������� = " << summ / (*one).d << endl<<endl;
	//************�������� ������ ���� ��-��******************************************************
	cout << "********************************�������� ������ ���� ���������***********"<<endl<<endl;
	if ((*one).d >= 2)
	{
		n* del_el;//����-�� ��-��
		
		for (int i = 0; i < 2; i++)
		{

			del_el = (*one).next;
			(*one).next = (*del_el).next;
		 //����� ��-�� ��� ������ ��������
			for (t1 = one; t1 != NULL; t1 = (*t1).next)
			cout << "��� ���� t1= " << t1 << " ���� ���� D=" << (*t1).d << " ���� ���� next=" << (*t1).next << endl;
		cout << endl;
		}
		(*one).d -= 2;
	
		
	}

	else
	{
		cout << "�� ������� ��-�� ��� ��������!!!!" << endl;
	} 
		
	system("pause");
	return 0;
}


