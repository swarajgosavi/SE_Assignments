/*
Assignment 8
Name : Swaraj Sachin Gosavi
Roll no : 21327
Batch : F3 [SE 3]

Implement a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array.
*/

#include <iostream>

using namespace std;

template<class T>
void sort(T a[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min]) min = j;
            if(min != i) swap(a[min], a[i]);
        }
    }
}

template<class X>
void swap(X &a, X &b){
    X temp = a;
    a = b;
    b = temp;
}

int main(){
    int x[5] = {10, 50, 30, 40, 20};
    float y[5] = {1.1, 5.5, 3.3, 4.4, 2.2};

    sort(x, 5);
    sort(y, 5);

    cout << "Sorted Integer Array : ";
    for(int i=0; i<5; i++) cout << x[i] << " ";
    cout << endl;

    cout << "Sorted Float Array : ";
    for(int i=0; i<5; i++) cout << y[i] << " ";
    cout << endl;

    return 0;
}