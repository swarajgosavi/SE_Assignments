/*
Assignment 2
Name : Swaraj Sachin Gosavi
Roll no : 21327
Batch : F3 [SE 3]

Develop a program in C++ to create a database of student’s information   system   containing   the   following   information: 
Name,  Roll  number,  Class,  Division,  Date  of  Birth,  Blood group, contact address, Telephone number, Driving license no. and   other.   
Construct   the   database   with   suitable   member functions.  
Make  use  of  constructor,  default  constructor,  copy constructor,  destructor,  static  member  functions,  friend  class, this   pointer,inline  code   and  dynamic   memory   allocation operators-new and delete as well as exception handling.
*/


#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

class Database{
    private:
        char name[20], cls[5], div[2], dob[10], bloodgrp[5];
        int roll;
    public:
        Database(){
            char *name = new char[40];
            char *cls = new char[5];
            char *div = new char[2];
            char *dob = new char[15];
            char *bloodgrp = new char[5];
            roll = 0;
        }
        Database(Database *obj){
            roll = obj->roll;
            strcpy(cls, obj->cls);
            strcpy(div, obj->div);
        }
        ~Database(){
            cout << this->name << " (Object) is destroyed";
        }
        friend class Information;
        static int count;
        static void TotalCount(){cout << "\n\nTotal number of records created : " << count;}
};

class Information{
    private:
        char address[30], telephone_no[15], license_no[10];
    public:
        Information(){
            strcpy(address, "");
            strcpy(telephone_no, "");
            strcpy(license_no, "");
        }
        void InputData(Database *obj);
        void Display(Database *obj);
        friend class Database;
};

int Database :: count = 0;

void Information :: InputData(Database *obj){
    cout << "\nROLL NO : ";
    cin >> obj->roll;
    cout << "\nNAME : ";
    cin >> obj->name;
    cout << "\nCLASS: ";
    cin >> obj->cls;
    cout << "\nDIVISION: ";
    cin >> obj->div;
    cout << "\nDATE OF BIRTH(DD-MM-YYYY): ";
    cin >> obj->dob;
    cout << "\nBLOOD GROUP: ";
    cin >> obj->bloodgrp;
    cout << "\nADDRESS: ";
    cin >> this->address;
    cout << "\nTELEPHONE NUMBER: ";
    cin >> this->telephone_no;
    cout << "\nDRIVING LICENSE NUMBER: ";
    cin >> this->license_no;
    obj->count++;
}

void Information :: Display(Database *obj){
    cout<< "\n" << setw(12) << obj->name << setw(5) << obj->roll << setw(6) << obj->cls << setw(5) << obj->div << setw(12) << obj->dob << setw(4)<< obj->bloodgrp << setw(12) << this->address << " " << setw(12) << this->telephone_no << " " << setw(12) << " " << this->license_no;
}

int main(){
    Database *d1,*a[10];
    Information *i1,*c[10];
    d1 = new Database;
    i1 = new Information;
    i1->InputData(d1);
    i1->Display(d1);

    Database *d2(d1);
    i1->Display(d2);

    delete d1;
    delete d2;
    delete i1;

    int n = 0, i, ch;
    char ans;
    do{
        cout << "\n\nMenu";
        cout << "\nEnter your choice";
        cout << "\n\t1.Input Record\n\t2.Display Record";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "\nEnter the details";
                do{
                    a[n] = new Database;
                    c[n] = new Information;
                    c[n]->InputData(a[n]);
                    n++;
                    cout << "\n\nDo you want to add more records?(y/n) : ";
                    cin >> ans;
                }while(ans == 'y' || ans == 'Y');
                break;
            case 2:
                cout<< "\n" << setw(12) << "NAME" << setw(5) << "ROLL" << setw(6) << "CLASS" << setw(5) << "DIV" << setw(12) << "DATE OF BIRTH" << setw(4)<< "BG" << setw(12) << "ADDRESS" << " " << setw(12) << "TELEPHONE NO" << " " << setw(12) << " " << "LICENSE NO";
            for(i=0; i<n; i++) c[i]->Display(a[i]);
            Database::TotalCount();
            break;
        }
        cout << "\n\nDo you want ot go to main menu?(y/n) : ";
        cin >> ans;
        cin.ignore(1, '\n');
    }while(ans == 'y' || ans == 'Y');
    return 0;
}