#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include<conio.h>
#include<time.h>
using namespace std;

template <class TypeElement>
struct Node
{
	TypeElement* data;
	Node* next;
	Node* prev;
};

template <class T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;
	void Add_To_Head(T* elem);
	void Delete_From_Head();
	void Delete_From_Tail();

public:
	void Clear();
	T* operator[](int index);
	List<T>& operator=(const List<T>& l);
	void Add_To_Tail(T* elem);
	List();
	List(const List<T>& l);
	~List();
	void Delete_All();
	void Delete_Someone(T* elem);
	void Print_All();
};

template<class T>
void List<T>::Clear()
{
	Delete_All();
}


template<class T>
List<T>::List()
{
	head = tail = NULL;
	count = 0;
}



template<class T>
List<T>::~List()
{
	Delete_All();
}
template<class T>
void List<T>::Delete_From_Head()
{
	Node<T>* tmp = head;
	head = head->next;
	delete tmp->data;
	delete tmp;
	count--;
}

template<class T>
void List<T>::Delete_From_Tail()
{
	Node<T>* tmp = tail;
	tail->prev->next = NULL;
	delete tmp->data;
	delete tmp;
	count--;
}

template<class T>
void List<T>::Delete_All()
{
	while (head != NULL)
		Delete_From_Head();
}

template<class T>
void List<T>::Add_To_Head(T* elem)
{
	Node<T>* tmp = new Node<T>;
	tmp->prev = NULL;
	tmp->data = elem;
	tmp->next = head;
	if (head != NULL)
	{
		head->prev = tmp;
		head = tmp;
	}
	else
	{
		head = tail = tmp;
	}
	count++;
}

template<class T>
void List<T>::Add_To_Tail(T* elem)
{
	Node<T>* tmp = new Node<T>;
	tmp->data = elem;
	tmp->next = NULL;
	tmp->prev = tail;
	if (head != NULL)
	{
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = tail = tmp;
	}
	count++;
}

template<class T>
void List<T>::Delete_Someone(T* elem)
{
	int k = 1;
	bool b = false;
	Node<T>* del = head;
	while (del != NULL)
	{
		if (*del->data == *elem)
		{
			b = true;
			break;
		}
		del = del->next;
		k++;
	}
	if (b)
	{
		if (k == 1)
			Delete_From_Head();
		else if (k == count)
			Delete_From_Tail();
		else
		{
			del->prev->next = del->next;
			del->next->prev = del->prev;
			delete del->data;
			delete del;
		}
		count--;
	}
	else
		cout << "Не знайдено!\n";
}

template<class T>
void List<T>::Print_All()
{
	Node<T>* tmp = head;
	while (tmp != NULL)
	{
		cout << *tmp->data;
		tmp = tmp->next;
	}
}

template<class T>
List<T>::List(const List<T>& l)
{
	Clear();
	this->head = this->tail = NULL;
	this->count = 0;
	Node<T>* temp = l.head;
	while (temp != NULL)
	{
		this->Add_To_Tail(temp->data);
		temp = temp->next;
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& l)
{
	this->head = this->tail = NULL;
	this->count = 0;
	Node<T>* temp = l.head;
	while (temp != NULL)
	{
		this->Add_To_Tail(temp->data);
		temp = temp->next;
	}
	return *this;
}

template<class T>
T* List<T>::operator[](int index)
{
	if ((index == 0) || (index >= 0 && index < this->count))
	{
		int k = 0;
		Node<T>* tmp = head;
		while (tmp != NULL)
		{
			if (k == index)
				return tmp->data;
			k++;
			tmp = tmp->next;
		}
	}
	else
	{
		cout << "Ви вийшли за межі масиву!\n";
		cout << "Буде повернутий нульовий елемент!\n";
		return head->data;
	}
}
