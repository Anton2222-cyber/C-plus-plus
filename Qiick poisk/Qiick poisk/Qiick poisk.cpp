// Qiick poisk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T>
void bubbleSort(T a[], long size) {
    long i, j;
    T x;
    for (i = 0; i < size; i++) { // i - номер прохода
        for (j = size - 1; j > i; j--) {
            // внутренний цикл прохода
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
        }
    }
}
int BinarySearch(int A[], int Lb, int Ub, int Key) {
    int M;
    while (1) {
        M = (Lb + Ub) / 2;
        if (Key < A[M])
            Ub = M - 1;
        else if (Key > A[M])
            Lb = M + 1;
        else
            return M;
        if (Lb > Ub)
            return -1;
    }
}



int main() {
    srand(time(NULL));
    const long SIZE = 10;
    int ar[SIZE];
    int key, ind;



    for (int i = 0; i < SIZE; i++) {
        ar[i] = rand() % 100;
        cout << ar[i] << "\t";
    }
    cout << "\n\n";



    bubbleSort(ar, 10);



    for (int i = 0; i < SIZE; i++) {
        cout << ar[i] << "\t";
    }
    cout << "\n\n";
    cout << "Enter any digit:";
    cin >> key;
    ind = BinarySearch(ar, 0, SIZE, key);
    cout << "Index - " << ind << "\t"; cout << "\n\n";
    return 0;
}