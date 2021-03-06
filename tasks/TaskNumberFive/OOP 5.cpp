#include "stdafx.h"
#include "OOP 5.h"

using namespace std;

Node::Node(int newData)
{
	data = newData;
	next = NULL;
}

Node::Node() {}

List::List() 
{
	head = NULL;
}

//добавление элемент по индексу
void List::insert(int newData, int index)
{
	if (index < 0) 
	{
		cout << "Ошибка: отрицательный индекс";
		return;
	}
	Node* curr = new Node(newData);
	Node* tmp = head;
	int i = 1;

	if (!head) 
	{
		head = curr;
	}
	else if (index == 1) 
	{
		curr->next = tmp;
		head = curr;
	}
	else 
	{
		while (i<index) 
		{
			if (!tmp->next) 
			{
				cout << "Конец списка достигнут, узел добавлен в конец" << endl;
				break;
			}
			tmp = tmp->next;
			i++;
		}
		curr->next = tmp->next;
		tmp->next = curr;
	}
}
//переместить элемент в конец
void List::push_back(int newData) 
{
	Node* curr = new Node(newData);
	Node* tmp = head;

	if (!head) 
	{
		head = curr;
	}
	else 
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = curr;
	}
}
// удаление элемента
void List::deleteByIndex(int index) 
{
	Node* curr = head;
	int i = 1;
	while (i < index) 
	{
		if (curr->next)
			curr = curr->next;
		else 
		{
			cout << "Узел с индексом " << index << " не существует в списке" << endl;
			return;
		}
		i++;
	}

	if (!curr->next) 
	{
		cout << "Узел с индексом " << index << " не существует в списке" << endl;
		return;
	}

	Node* tmp = curr->next;

	if (index == 1) 
	{
		head = tmp;
		delete curr;
		return;
	}

	if (!curr->next->next) 
		curr->next = NULL;
	else
		curr->next = curr->next->next;
	delete tmp;
}
// удаление списка
void List::deleteList()
{
	if (!head) 
	{
		cout << "Список пуст" << endl;
		return;
	}

	while (head->next)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}

	delete head;
	head = NULL;
}
// напечатать
void List::printList()
{
	if (!head)
	{
		cout << "Список пуст" << endl;
		return;
	}
	Node* curr = head;
	while (curr) 
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

//разбитие списка
void List::split(List* list, List* list1, List* list2, int N) {
	Node *curr1 = NULL, *curr2 = NULL, *tmp = list->head;
	while (tmp) 
	{
		if (tmp->data > N) 
		{
			if (!curr1)
			{
				list1->head = tmp;
				curr1 = list1->head;
			}
			else
			{
				curr1->next = tmp;
				curr1 = curr1->next;
			}
		}
		else
		{
			if (!curr2)
			{
				list2->head = tmp;
				curr2 = list2->head;
			}
			else
			{
				curr2->next = tmp;
				curr2 = curr2->next;
			}

		}
		tmp = tmp->next;
	}
	if(curr1)
		curr1->next = NULL;
	if(curr2)
		curr2->next = NULL;
	list->head = NULL;
}