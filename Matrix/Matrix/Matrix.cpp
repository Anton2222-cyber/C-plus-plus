#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>

using namespace std;

class Matrix
{
    float** arr;
    int a;
    int b;
    float Suma_Column(int i)
    {
        float sum = 0;
        for (int j = 0; j < a; j++)
        {
            sum += arr[j][i];
        }
        return sum;
    }
    
public:
    Matrix(const Matrix& obj)

    {


        a = obj.a;
        b = obj.b;
        arr = new float* [obj.a];
        for (int i = 0; i < a; i++)
        {
            arr[i] = new float[b];
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                arr[i][j] = obj.arr[i][j];
            }
        }

        

    }
    Matrix(int a, int b)
    {
        this->a = a;
        this->b = b;
        arr = new float*[a];
        for (int i = 0; i < a; i++)
        {
            arr[i] = new float[b];
        }
   /*     int k = 1;*/
        /*for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                arr[i][j] = k;
                k++;
                cout <<arr[i][j]<<" ";
            }
            cout << endl;
        }*/
    }
    Matrix()
    {
        this->a = 3;
        this->b = 3;
        arr = new float* [a];
        for (int i = 0; i < a; i++)
        {
            arr[i] = new float[b];
        }
        /*     int k = 1;*/
             /*for (int i = 0; i < a; i++)
             {
                 for (int j = 0; j < b; j++)
                 {
                     arr[i][j] = k;
                     k++;
                     cout <<arr[i][j]<<" ";
                 }
                 cout << endl;
             }*/
    }
    void Delete_Memory()
    {
        for (int i = 0; i < a; i++)
        {
            if(arr[i]!=NULL)
            delete[] arr[i];
        }
        if(arr!=NULL)
        delete arr;
    }
    ~Matrix()
    {
        Delete_Memory();
    }
    friend ostream& operator<<(ostream& out, const Matrix& obj);

    friend istream& operator>>(istream& in, Matrix& obj);

    Matrix operator+(const Matrix& obj)
    {
        Matrix tmp(obj.a, obj.b);
        for (int i = 0; i < obj.a; i++)
        {
            for (int j = 0; j < obj.b; j++)
            {
                tmp.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
            }
        }
        return tmp;
    }
    Matrix operator*(const int& obj)
    {
        Matrix tmp(this->a, this->b);
        for (int i = 0; i < tmp.a; i++)
        {
            for (int j = 0; j < tmp.b; j++)
            {
                tmp.arr[i][j] = this->arr[i][j] * obj;
            }
        }
        return tmp;
    }
    Matrix Transpon()
    {
        Matrix tmp(b, a);
        for (int i = 0; i <a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                tmp.arr[j][i] = arr[i][j];
            }
        }
        return tmp;
    }
    int Counter_Ne_Null()
    {
        int count = 0;
        for (int i = 0; i < b; i++)
        {
            int tmp = 0;
            for (int j = 0; j < a; j++)
            {
                if (arr[j][i] != 0)
                    tmp++;
            }
            if (tmp == a)
                count++;
            tmp = 0;
        }
        return count;
    }
    int Counter_Less_A_More_B(float A, float B)
    {
        int count = 0;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (arr[i][j]< A && arr[i][j]>B)
                    count++;
            }
        }
        return count;
    }
    
    void Sort_By_Sum()
    {
        bool b;

        do {
            b = false;
            for (int i = 0; i < this->b - 1; i++) {
                if (Suma_Column(i) > Suma_Column(i + 1))
                {
                    for (int j = 0; j < a; j++)
                    {
                        swap(arr[j][i], arr[j][i + 1]);
                    }

                   /* char temp[size];
                    int temp2;
                    strcpy(temp, pricelist[i].element);
                    strcpy(pricelist[i].element, pricelist[i + 1].element);
                    strcpy(pricelist[i + 1].element, temp);


                    temp2 = pricelist[i].cost;
                    pricelist[i].cost = pricelist[i + 1].cost;
                    pricelist[i + 1].cost = temp2;

                    temp2 = pricelist[i].number;
                    pricelist[i].number = pricelist[i + 1].number;
                    pricelist[i + 1].number = temp2;*/

                    b = true;
                }
            }
        } while (b);
    }
};
ostream& operator<<(ostream& out, const Matrix& obj)
{

    cout << "------------------------------------\n";

    for (int i = 0; i < obj.a; i++)
    {
        for (int j = 0; j < obj.b; j++)
        {
            cout << obj.arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "------------------------------------\n";

    return out;

}

istream& operator>>(istream& in, Matrix& obj)

{

    obj.Delete_Memory();

    cout << "Введіть скільки рядків хочете написати ->";

    in >> obj.a;
    cout << "Введіть скільки стопчиків хочете написати ->";

    in >> obj.b;

    obj.arr = new float* [obj.a];

    for (int i = 0; i < obj.a; i++)
    {
        obj.arr[i]=new float[obj.b];
    }
    for (int i = 0; i < obj.a; i++)
    {
        for (int j = 0; j < obj.b; j++)
        {
            cout << "Введіть [" << i << "][" << j << "] елемент ->";
            in >> obj.arr[i][j];
        }
    }

    return in;

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Matrix m;
    cin >> m;
    cout << m;

   /* Matrix m2;
    cin >> m2;
    cout << m2;

    cout << (m + m2);*/
    /*cout << (m * 2);*/
   /* cout << m.Transpon();*/
   /* cout << m.Counter_Ne_Null();*/
    /*cout << m.Counter_Less_A_More_B(4, 1);*/
    m.Sort_By_Sum();
    cout << m;
}


