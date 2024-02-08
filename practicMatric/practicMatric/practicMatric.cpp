#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

using namespace std;

class Matrix
{
    float** matrix;
    int a;
    int b;
	void DeleteMemory()
	{
		for (int i = 0; i < a; i++)
		{
			if (matrix[i] != NULL)
				delete[] matrix[i];
		}
		if (matrix != NULL)
			delete[] matrix;
	}
public:
	/*float** Get_Matrix()
	{
		return matrix;
	}*/
	Matrix& operator=(const Matrix& obj)
	{
		matrix = new float* [obj.a];
		a = obj.a;
		b = obj.b;
		for (int i = 0; i < a; i++)
		{
			matrix[i] = new float[b];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{

				matrix[i][j] = obj.matrix[i][j];
			}

		}
		return *this;
	}
	Matrix(const Matrix& obj)
	{

		matrix = new float* [obj.a];
		a = obj.a;
		b = obj.b;
		for (int i = 0; i < a; i++)
		{
			matrix[i] = new float[b];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				
				matrix[i][j] = obj.matrix[i][j];
			}
			
		}
	}
	Matrix()
	{
		this->a = 2;
		this->b = 2;
		matrix = new float* [a];
		for (int i = 0; i < a; i++)
		{
			matrix[i] = new float[b];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	Matrix(int a,int b)
	{
		this->a = a;
		this->b = b;
		matrix = new float* [a];
		for (int i = 0; i < a; i++)
		{
			matrix[i] = new float[b];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	
	~Matrix()
	{
		DeleteMemory();
		
	}
	friend ostream& operator<<(ostream& out, const Matrix& matrix);
	friend istream& operator>>(istream& in, Matrix& obj);
	
	Matrix operator+(const Matrix& obj)
	{
		Matrix m(obj.a, obj.b);
		for (int i = 0; i < obj.a; i++)
		{
			for (int j = 0; j < obj.b; j++)
			{
				m.matrix[i][j] = this->matrix[i][j] + obj.matrix[i][j];
				
			}
		}
		return m;
	}
	Matrix operator*(const float& obj)
	{
		Matrix tmp = *this;
		for (int i = 0; i < tmp.a; i++)
		{
			for (int j = 0; j < tmp.b; j++)
			{
				tmp.matrix[i][j] *= obj;
			}
		}
		return tmp;
	}
	Matrix Transposition()
	{
		Matrix tmp(b,a);
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				tmp.matrix[i][j] = matrix[j][i];
			}
		}
		return tmp;
	}
	
};
ostream& operator<<(ostream& out, const Matrix& matrix)
{
	cout << "------------------------------------\n";
	for (int i = 0; i < matrix.a; i++)
	{
		for (int j = 0; j < matrix.b; j++)
		{
			cout << matrix.matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------\n";
	return out;
}
istream& operator>>(istream& in, Matrix& obj)
{
	obj.DeleteMemory();
	cout << "Введіть скільки рядків ->";
	in >> obj.a;
	cout << "Введіть скільки стовпців ->";
	in >> obj.b;
	obj.matrix = new float* [obj.a];
	for (int i = 0; i < obj.a; i++)
	{
		obj.matrix[i]= new float[obj.b];
	}
	
	for (int i = 0; i < obj.a; i++)
	{
		for (int j = 0; j < obj.b; j++)
		{
			cout << "Введіть [" << i<<"]["<<j<<"] елемент ->";
			
			cin >> obj.matrix[i][j];
		}
		
	}
	return in;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Matrix m(2,2);
	cin >> m;
	cout << m;
	Matrix m2(2, 2);
	cin >> m2;
	cout << m2;
	Matrix m3 = m + m2;
	cout << m3;
	m3 = m3*2;
	cout << m3;
	cout << m.Transposition();
}


