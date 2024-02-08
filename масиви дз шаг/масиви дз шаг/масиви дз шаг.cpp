#include<iostream>
using namespace std;

class A
{
	int a = 10;
public:
	A(int pa) :a(pa)
	{
		cout << "First:";
	}
	A()
	{
		cout << "Second:";
	}
	static int GetA()
	{
		return this->a;
	}
};

int main()
{
	A obj;
	cout << obj.GetA();

	return 0;
}