/*
Assignment 11
Name : Swaraj Sachin Gosavi
Roll no : 21327
Batch : F3 [SE 3]

Write C++ program using STL for sorting and searching user defined records such as Item records 
(Item code, name, cost, quantity etc) using vector container.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class item{
public:
    string name;
    int cost, code, quantity;
};

item insert(){
    item temp;
    cout << "\nEnter the product details" << endl;
    cout << "Item code : ";
    cin >> temp.code;
    cout << "Item name : ";
    cin >> temp.name;
    cout << "Item cost (Rupees) : ";
    cin >> temp.cost;
    cout << "Quantity : ";
    cin >> temp.quantity;
    return temp;
}

bool cname(const item& lhs, const item& rhs) {
    return lhs.name < rhs.name;
}

bool ccost(const item& lhs, const item& rhs) {
    return lhs.cost < rhs.cost;
}

bool ccode(const item& lhs, const item& rhs) {
    return lhs.code < rhs.code;
}

bool cquant(const item& lhs, const item& rhs) {
    return lhs.quantity < rhs.quantity;
}

void searching(vector<item> a){
    char ch;
    vector<item> :: iterator p;
    cout << "\n\nEnter the parameter to search" << endl;
    cout << "1. Item Name\n2. Item code" << endl;
    cout << "Choice : ";
    cin >> ch;
    string name;
    int code;
    switch(ch){
        case '1':
            cout << "Name : ";
            cin >> name;
            for(p = a.begin(); p!=a.end(); p++){
                if(p->name == name) {
                    cout << "Found";
                    return;
                }
            }
            cout << "404 Not Found";
            break;
        case '2':
            cout << "Code : ";
            cin >> code;
            for(p = a.begin(); p!=a.end(); p++){
                if(p->code == code) {
                    cout << "Found";
                    return;
                }
            }
            cout << "404 Not Found";
            break;
    }
}

int main(){
    vector<item> i;
    bool f=1;
    char ch;

    vector<item> :: iterator p;
    while(f){
        cout << "\n\nEnter your choice" << endl;
        cout << "1. Add records\n2. Sort\n3. Search\n4. Display\n5. Exit" << endl;
        cout << "Choice : " ;
        cin >> ch;
        switch(ch){
            case '1':
                i.push_back(insert());
                break;
            case '2':
                cout << "\n\nEnter the parameter to sort" << endl;
                cout << "1. Item Name\n2. Item cost\n3. Item code\n4. Quantity" << endl;
                cout << "Choice : ";
                cin >> ch;
                switch(ch){
                    case '1':
                        sort(i.begin(), i.end(), &cname);
                        break;
                    case '2':
                        sort(i.begin(), i.end(), &ccost);
                        break;
                    case '3':
                        sort(i.begin(), i.end(), &ccode);
                        break;
                    case '4':
                        sort(i.begin(), i.end(), &cquant);
                        break;
                }
                for(p = i.begin(); p != i.end(); p++){
                    cout << p->code << " " << p->name << setw(10) << p->cost << setw(10) << p->quantity << endl;
                }
                break;
            case '3':
                searching(i);
                break;
            case '4':
                for(p = i.begin(); p != i.end(); p++){
                    cout << p->code << " " << p->name << setw(10) << p->cost << setw(10) << p->quantity << endl;
                }
                break;
            case '5':
                f = 0;
                break;
            default:
                cout << "Enter a valid choice " << endl;
        }
    }
    return 0;
}