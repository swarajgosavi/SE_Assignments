/*
Assignment 1
Name : Swaraj Sachin Gosavi
Roll no : 21327
Batch : F3 [SE 3]

Implement  a  class  Complex  which represents  the  Complex Number  data  type.  
Implement  the  following  
1.  Constructor (including  a  default  constructor  which  creates  the  complex number  0+0i).  
2.  Overload  operator+  to  add  two  complex numbers.  
3.  Overload  operator*  to  multiply  two  complex numbers.  
4.  Overload  operators  <<  and  >>  to  print  and  read Complex Numbers.
*/

#include<iostream>
using namespace std;

class Complex{
    private:
        float x, y;

    public:
        Complex(){
            x = 0;
            y = 0;
        }
        Complex operator+(Complex);
        Complex operator*(Complex);
        friend ostream & operator<<(ostream &, Complex &);
        friend istream & operator>>(istream &, Complex &);
};

Complex Complex :: operator+(Complex obj){
    Complex temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

Complex Complex :: operator*(Complex obj){
    Complex temp;
    temp.x = (x * obj.x) - (y * obj.y);
    temp.y = (x * obj.y) + (y * obj.x);
    return temp;
}

istream & operator>>(istream &din, Complex &obj){
    cout << "Enter the real part : ";
    din >> obj.x;
    cout << "Enter the imaginary part : ";
    din >> obj.y;
    return din;
}

ostream & operator<<(ostream &dout, Complex &obj){
    dout << obj.x << " + " << obj.y << "i" << endl;
    return dout;
}

int main(){
    Complex a, b, c, d;
    cin >> a;
    cout << a;

    cin >> b;
    cout << b;

    c = a + b;
    cout << "Addition : ";
    cout << c;

    d = a * b;
    cout << "Multiplication : ";
    cout << d;
    return 0;
}