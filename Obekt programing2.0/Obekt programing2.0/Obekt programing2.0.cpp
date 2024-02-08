#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include<conio.h>
#include<time.h>
#include "Header.h"
using namespace std;

class Worker
{
protected:
	char* lastname;
	char* firstname;
	char* surname;
	char* boss;
	char* responsibilities;
	List<Worker> people;
public:
	Worker()
	{
		/*cout << "Worker constructor\n";*/
		lastname = NULL;
		firstname = NULL;
		surname = NULL;
		boss = NULL;
		responsibilities = NULL;

	}
	Worker(const char* lastname, const char* firstname, const char* surname, const char* boss, const char* responsibilities)
	{
		/*cout << "Worker constructor\n";*/
		this->lastname = new char[strlen(lastname) + 1];
		this->firstname = new char[strlen(firstname) + 1];
		this->surname = new char[strlen(surname) + 1];
		this->boss = new char[strlen(boss) + 1];
		this->responsibilities = new char[strlen(responsibilities) + 1];
		strcpy(this->lastname, lastname);
		strcpy(this->firstname, firstname);
		strcpy(this->surname, surname);
		strcpy(this->boss, boss);
		strcpy(this->responsibilities, responsibilities);
	}
	char* Get_Lastname()
	{
		return lastname;
	}
	char* Get_name()
	{
		return firstname;
	}
	virtual ~Worker()
	{
		/*cout << "Worker destructor\n";*/
		if (this->lastname != NULL)
			delete[] this->lastname;
		if (this->firstname != NULL)
			delete[]this->firstname;
		if (this->surname != NULL)
			delete[]this->surname;
		if (this->boss != NULL)
			delete[]this->boss;
		if (this->responsibilities != NULL)
			delete[]this->responsibilities;

	}
	void Add_People(Worker* worker)
	{
		people.Add_To_Tail(worker);
	}
	void Show_PIB()
	{
		cout << lastname << " " << firstname << " " << surname << endl;
	}
	void Show_Peoples()
	{
		cout << "Підлеглі:\n";
		people.Print_All();
	}
	virtual void Show_Worker() = 0;
	friend ostream& operator<<(ostream& os, const Worker& p);
	bool operator==(const Worker& obj)
	{
		if (strcmp(this->firstname, obj.firstname) == 0 && strcmp(this->lastname, obj.lastname) == 0)
			return true;
		return false;
	}
	Worker(const Worker& obj)
	{

		this->lastname = new char[strlen(obj.lastname) + 1];
		this->firstname = new char[strlen(obj.firstname) + 1];
		this->surname = new char[strlen(obj.surname) + 1];
		this->boss = new char[strlen(obj.boss) + 1];
		this->responsibilities = new char[strlen(obj.responsibilities) + 1];

		strcpy(this->lastname, obj.lastname);
		strcpy(this->firstname, obj.firstname);
		strcpy(this->surname, obj.surname);
		strcpy(this->boss, obj.boss);
		strcpy(this->responsibilities, obj.responsibilities);
		this->people = obj.people;
	}
	Worker& operator=(const Worker& obj)
	{
		this->lastname = new char[strlen(obj.lastname) + 1];
		this->firstname = new char[strlen(obj.firstname) + 1];
		this->surname = new char[strlen(obj.surname) + 1];
		this->boss = new char[strlen(obj.boss) + 1];
		this->responsibilities = new char[strlen(obj.responsibilities) + 1];

		strcpy(this->lastname, obj.lastname);
		strcpy(this->firstname, obj.firstname);
		strcpy(this->surname, obj.surname);
		strcpy(this->boss, obj.boss);
		strcpy(this->responsibilities, obj.responsibilities);
		this->people = obj.people;
		return *this;
	}
};
ostream& operator<<(ostream& os, const Worker& w)
{
	os << w.lastname << " " << w.firstname << " " << w.surname << endl;
	os << "Обов'язки: " << w.responsibilities << endl;
	os << "Керівник: " << w.boss << endl;
	cout << "---------------------------------\n";
	return os;
}
class Manager :public Worker
{
public:
	Manager(const char* lastname, const char* firstname, const char* surname, const char* boss, const char* responsibilities) :Worker(lastname, firstname, surname, boss, responsibilities)
	{
	}
	~Manager()
	{

	}
	void Show_Worker()
	{
		cout << "Менеджер\n";
		cout << lastname << " " << firstname << " " << surname << endl;
		cout << "Обов'язки: " << responsibilities << endl;
		cout << "Керівник: " << boss << endl;
	}
};
class Coder :public Worker
{
public:
	Coder(const char* lastname, const char* firstname, const char* surname, const char* boss, const char* responsibilities) :Worker(lastname, firstname, surname, boss, responsibilities)
	{
	}
	~Coder()
	{

	}
	void Show_Worker()
	{
		cout << "Молодший програміст\n";
		cout << lastname << " " << firstname << " " << surname << endl;
		cout << "Обов'язки: " << responsibilities << endl;
		cout << "Керівник: " << boss << endl;
	}
};
class Developer :public Worker
{
public:
	Developer(const char* lastname, const char* firstname, const char* surname, const char* boss, const char* responsibilities) :Worker(lastname, firstname, surname, boss, responsibilities)
	{
	}
	~Developer()
	{

	}
	void Show_Worker()
	{
		cout << "Розробник\n";
		cout << lastname << " " << firstname << " " << surname << endl;
		cout << "Обов'язки: " << responsibilities << endl;
		cout << "Керівник: " << boss << endl;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List<Worker> list;
	Worker* a = new Manager("Лащ", "Антон", "Вадимович", "Володимир Іванов", "Керувати проектом");
	list.Add_To_Tail(a);
	list[0]->Add_People(new Coder("Деркач", "Антон", "Вадимович", "Володимир Іванов", "Писати код"));
	list[0]->Add_People(new Developer("Жилко", "Василь", "Романович", "Антон Вадимович", "Розробляти проект"));
	list.Add_To_Tail(new Manager("Лащ", "Антон", "Вадимович", "Володимир Іванов", "Керувати проектом"));
	list[1]->Add_People(new Coder("Деркач", "Антон", "Вадимович", "Володимир Іванов", "Писати код"));
	list[1]->Add_People(new Developer("Жилко", "Василь", "Романович", "Антон Вадимович", "Розробляти проект"));
	list.Delete_Someone(a);
	cout << "///////////\n";
	list[0]->Show_PIB();
	list[0]->Show_Peoples();
	cout << "///////////\n";
	list.Print_All();
	list.Delete_All();
	return 0;
}