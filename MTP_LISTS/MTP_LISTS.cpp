#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;

struct n
{
	int d;
	n* next; // - указатель на следующий адрес
};
//typedef n *PN;// создать тип PN, аналогичный типу структуры n


int main(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	int list_siz;
	cout << "Введите кол-во эл-ов списка: "; cin >> list_siz; cout << endl;

	n* one;//первый эл-нт списка
	n* t;
	//------------СОЗДАНИЕ УЗЛА СПИСКА
	t = new (n);
	(*t).next = NULL;
	(*t).d = list_siz;//хранится размер списка

	one = t;

	int elem_list = 0;
	for (int i = 0; i < list_siz; i++)
	{
		cout << "Введите очередной эл-нт списка: "; cin >> elem_list; cout << endl;
		//**************ВСТАВКА В КОНЕЦ СПИСКА*****************************
		n* elem;
		elem = new (n);
		(*elem).next = NULL;//он станет конечным для списка
		(*elem).d = elem_list;//инициализировали инф поле нового эл-та 

		(*t).next = elem;
		t = (*t).next;
	}
	cout << endl;
	n* t1;
	for (t1 = one; t1 != NULL; t1 = (*t1).next)
		cout << "адр указ t1= " << t1 << " знач поля D=" << (*t1).d << " знач поля next=" << (*t1).next << endl;
	cout << endl;

	//*************************СРЕднее арифм-ое************************************
	int summ = 0;
	for (t1 = (*one).next; t1 != NULL; t1 = (*t1).next)//ср арифм-ое
		summ += (*t1).d;
	cout << "Среднее арифметическое=" << summ / (*one).d << endl;
	//************УДАЛЕНИЕ ПЕРВЫХ ДВУЧ ЭЛ-ОВ******************************************************
	free(t1);
	if ((*one).d >= 2)
	{
		n* del_el;//удал-ый эл-нт
		for (int i = 0; i < 2; i++)
		{

			del_el = (*one).next;
			(*one).next = (*del_el).next;
		}
		(*one).d -= 2;
		n* t1;
		for (t1 = one; t1 != NULL; t1 = (*t1).next)
			cout << "адр указ t1= " << t1 << " знач поля D=" << (*t1).d << " знач поля next=" << (*t1).next << endl;
		cout << endl;
		free(t1);
	}

	else
	{
		cout << "Не хватает эл-ов для удаления!!!!" << endl;
	}
	bla-bla русский 
		system("pause");
	return 0;
}


