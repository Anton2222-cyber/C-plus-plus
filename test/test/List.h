#pragma once


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
	void Delete_From_Tail();
	void Delete_From_Head();
public:
	void Clear();
	T* operator[](int index);
	List<T>& operator=(const List<T>& l);
	void Add_To_Tail(T* elem);
	List();
	List(const List<T>& l);
	~List();
	void Delete_All();
	void Delete_Someone(int index_);
	void Print_All();
};

