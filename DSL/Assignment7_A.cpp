/*
The ticket booking system of Cinemax theatre has to be implemented using C++ program. 
There are 10 rows and 7 seats in each row. 
Doubly circular linked list has to be maintained to keep track of free seats at rows. 
Assume some random booking to start with.
Use array to store pointers (Head pointer) to each row. 
On demand 
a) The list of available seats is to be displayed 
b) The seats are to be booked 
c) The booking can be cancelled. 
*/

#include<iostream>

using namespace std;

class Node{
public:
    Node *prev;
    int value;
    bool status;
    Node *next;

    Node(int v){
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class Cinemax{
private:
    Node *head[10], *tail[10];
public:
    Cinemax(){
        for(int i =1; i<=10; i++) head[i] = NULL;
    }
    void seats();
    void display();
    void book();
    void cancel();
    void available();
};

void Cinemax :: seats(){
    Node *temp;
    for(int i=1; i<=10; i++){
        head[i] = new Node(0);
        head[i]->next = head[i];
        head[i]->prev = head[i];

        temp = head[i];
        tail[i] = temp;
        for(int j=1; j<7; j++){
            temp->next = new Node(0);
            temp->next->prev = temp;
            temp = temp->next;
            head[i]->prev = temp;
            temp->next = head[i];
            tail[i] = temp;
        }
    }
}

void Cinemax::display(){
    Node *temp;
    for(int i=1; i<=10; i++){
        temp = head[i];
        cout << i << " ";
        do{
            cout << temp->value << " ";
            temp = temp->next;
        }while(temp != head[i]);
        cout << endl;
    }
}

void Cinemax :: book(){
    int x, y;
    int n;
    Node *temp;
    cout << "Enter number of tickets to book : " <<  endl;
    cin >> n;
    while(n>0){
        cout << "Enter row : ";
        cin >> x;
        cout << "Enter seat number : ";
        cin >> y;
        if(x >= 1 && x <= 10 && y >=1 && y <= 7){
            temp = head[x];
            for(int i=0; i<y-1; i++){
                temp = temp->next;
            }
            temp->value = 1;
            n--;
        }
        else cout << "Not available " << endl;
    }
}

void Cinemax :: cancel(){
    Node *temp;
    int x, y, n;
    cout << "Enter the number of seats to cancel : ";
    cin >> n;
    while(n>0){
        cout << "Enter the row : ";
        cin >> x;
        cout << "Enter seat number : ";
        cin >> y;
        temp = head[x];
        for(int i=0; i<y-1; i++){
            temp = temp->next;
        }
        if(temp->value == 1) temp->value = 0;
        else cout << "This seat is not booked";
        n--;
    }
    display();
}

void Cinemax :: available(){
    int count = 70;
    Node *temp;
    for(int x=1; x<=10; x++){
        temp = head[x];
        do{
            if(temp->value == 1){
                count--;
            }
            temp = temp->next;
        }while(temp != head[x]);
    }
    cout << "No of available seats : " << count << endl;
}

int main(){
    Cinemax ticket;
    int c;
    ticket.seats();
    while(true){
        cout << "Menu" << endl;
        cout << "1) Book seat" << endl;
        cout << "2) No of available seats" << endl;
        cout << "3) Cancle seats" << endl;
        cout << "4) Display available seats" << endl;
        cout << "5) Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> c;
        switch(c){
            case 1:
                ticket.book();
                ticket.display();
                break;
            case 2:
                ticket.available();
                break;
            case 3:
                ticket.cancel();
                break;
            case 4:
                ticket.display();
                break;
            case 5:
                exit(1);
        }
    }
    return 0;
}
