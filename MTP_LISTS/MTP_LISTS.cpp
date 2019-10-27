#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;

struct List
{
	int d;
	List* next; // - указатель на следующий адрес
};
//typedef n *PN;// создать тип PN, аналогичный типу структуры n
List* init_List()//создание первого эл-та
{
	List* one;//первый эл-нт списка
	one = new (List);
	(*one).d = 0;//кол-во эл-ов = 0 
	(*one).next = NULL;
	
	return one;//указатель передали
	delete(one);// освободили память
}

void insert_elt (List* &last_elt,int new_elt)//добавление после головы  ?? Почему здесь нужна ссылка
{
	List* elem;
	elem = new (List);
	(*elem).next = NULL;//он станет конечным для списка
	(*elem).d = new_elt;//инициализировали инф поле нового эл-та 

	(*last_elt).next = elem;//меняем указатель последнего эл-та списка, чтобы он указывал на вновь созданный
	last_elt = elem;//передвигаем указатель чтобы он указывал вновь на новый последний эл-нт
	
}

void del_List(List* &head)//указатель на голову списка ?? Присваивает голове какой-то адрес(ненулевой)
{
	delete(head);
}
void null_List(List* &head)//присвоим NULL head
{
	head = NULL;
}
void del_List_clr_all_elts (List* &head)
{
	
	while (head!=NULL)
	{
		List* tmp;
		tmp = head;//хр-ся текущий указатель
		(*tmp).d = rand();//подчистим заодно данные (необяз-но)
		head = (*head).next;//переходим на следующий эл-нт после головы
		//delete(tmp);//удаляем указатель ??ОН ВЕДЬ ТУПО В НУЛЛ ЗАГОНЯЕТСЯ - !!ОН ПОЧЕМУ-ТО РАНДОМНОМУ УЧАСТКУ ПАМЯТИ ПРИСВАИВАЕТСЯ
		tmp = NULL;
	}
}
int average_ariphmetics(List* head)
{
	int sum=0;
	List* i;//указатель для продв-ия по списку
	
	if ((*head).d > 0)//Если есть ходь один эл-нт, а не только голова
	for (i = (*head).next; i != NULL; i = (*i).next)//складываем со второго эл-та 1-ый - head
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
	List* i;//указатель для продв-ия по списку
	i = head;
	if (i == NULL)
	{
		cout << "СПИСОК УДАЛЁН((((((" << endl;
	}
	else
	{
	  for (; i != NULL; i = (*i).next)
		cout << "адр указ t1= " << i << " знач поля D=" << (*i).d << " знач поля next=" << (*i).next << endl;
	    cout<< endl;
	}
	
}
void del_1n2_elts(List* &head)
{
	if ((*head).d >= 2)
	{
		List* del_el;//удал-ый эл-нт

		for (int i = 0; i < 2; i++)
		{

			del_el = (*head).next;
			(*head).next = (*del_el).next;//присоединяем голову к эл-ту после удаляемого
			(*head).d --;
			//ВЫВОД ЭЛ-ОВ ПРИ КАЖДОМ УДАЛЕНИИ
			print_List(head);
		}
		
	}
}
int main(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	
	int list_siz;
	cout << "Введите кол-во эл-ов списка: "; cin >> list_siz; cout << endl;
	
	//****************************** Инициализация *********************************
	
	List* head = init_List();//инициализация стр-ры 
	
	 //****************************** Вставка эл-ов в список *********************************
	
	List* ins_pointer = head;//сначала указатель вставки располагается на 1-ом эл-те
	int inp_elt;//эл-нт для вставки 
	for (int i = 0; i < list_siz; i++)
	{
		cout << "Введите очередной эл-нт списка: ";
		cin >> inp_elt;
		insert_elt(ins_pointer, inp_elt);
		//ins_pointer = (*ins_pointer).next;
		head->d++;//Увеличиваем счетчик эл-ов списка
		print_List(head);
		cout << endl;
	}
	//delete(ins_pointer);//удал-ем указ-ль после вставки	ТАК НЕЛЬЗЯ ДЕЛАТЬ ЛОЛ
	//**********ЭТО ПРАВИЛЬНО:
	ins_pointer = NULL;//Нельзя удалять указатель не обратив в NULL можно так удалить эл-нт
	free(ins_pointer);

	//****************************** Среднее арифм-ое эл-ов списка *********************************
	cout<<"Среднее арифм-ое для эл - ов списка = "<<average_ariphmetics(head)<<endl;
	cout << endl;
	//***************************** Удаление первых двуч эл-ов *****************************
	cout << "Удаление первого и второго эл-та (если возможно):" << endl;
	del_1n2_elts(head);
	//****************************** Удаление списка *********************************
	cout << "Удаление ВСЕГО списка:" << endl;
	//del_List(head);// получ-ся просто теряем указатель на голову
	//***** 1 ВАРИАНТ Тупо заNULL голову и всё *****
	/*null_List(head);
	print_List(head);*/
	// 2 ВАРИАНТ ЧИСТИМ ИНФ. ПОЛЯ И ВСЕ указатели зануляем
	del_List_clr_all_elts(head);
	print_List(head);
	
	system("pause");
	return 0;
}


