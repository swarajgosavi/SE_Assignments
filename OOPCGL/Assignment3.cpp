/*
Assignment 3
Name : Swaraj Sachin Gosavi
Roll no : 21327
Batch : F3 [SE 3]

Imagine  a  publishing  company  which  does  marketing  for  book  and  audio  cassette versions.  
Create  a  class  publication  that  stores  the  title  (a  string)  and  price  (type float)  of  publications.  
From  this  class  derive  two  classes:  book  which  adds  a  page count (type int) 
and tape which adds a playing time in minutes (type float). 
Write a program  that  instantiates  the  book  and  tape  class,  allows  user  to  enter  data  and displays the data members. 
If an exception is caught, replace all the data membervalues with zero values.
*/

#include<iostream>
#include<cstring>

using namespace std;

class publication{
protected:
    char title[50];
    float price;
public:
    publication(char *s, float a){
        strcpy(title, s);
        price = a;
    }
    virtual void display() = 0;
};

class book : public publication{
private:
    float pages;
public:
    book(char *s, float a, float p) : publication(s, a){
        pages = p;
    }
    void display();
};

class tape : public publication{
private:
    float time;
public:
    tape(char *s, float a, float t) : publication(s, a){
        time = t;
    }
    void display();
};

void book :: display(){
    cout << "\nTitle : " << title;
    cout << "\nPages : " << pages;
    cout << "\nPrice : " << price;
}

void tape :: display(){
    cout << "\nTitle : " << title;
    cout << "\nPlay Time : " << time;
    cout << "\nPrice : " << price;
}

int main(){
    char *title = new char[30];
    float price, time;
    int pages;

    try{
        cout << "\nEnter Book Details\n";
        cout << "Title : "; cin >> title;
        cout << "Price : "; cin >> price;
        cout << "Pages : "; cin >> pages;
        throw(pages);
    }
    catch(...){
        price = 0;
        pages = 0;
        time = 0;
    }

    book book1(title, price, pages);

    try{
        cout << "\nEnter Tape Details\n";
        cout << "Title : "; cin >> title;
        cout << "Price : "; cin >> price;
        cout << "Play time (mins) : "; cin >> time;
        throw(title);
    }
    catch(...){
        price = 0;
        pages = 0;
        time = 0;
    }

    tape tape1(title, price, time);

    publication* ls[2];
    ls[0] = &book1;
    ls[1] = &tape1;

    cout << "\nPublication Details";
    cout << "\n\nBOOK";
    ls[0]->display();

    cout << "\n\nTape";
    ls[1]->display();

    return 0;
}