#include<iostream>

using namespace std;

class node{
public:
    int p;
    int info;
    node *next;
};

class Priority_Queue{
private:
    node *front, *rear;
public:
    Priority_Queue(){ front = NULL; rear = NULL;}
    void insert(int i, int p);
    void del();
    void show();
};

void Priority_Queue :: insert(int i, int p){
    node *temp, *q;
    temp = new node;
    temp->info = i;
    temp->p = p;
    if(front == NULL){
        front = new( node ) ; 
        front -> info = i ; 
        front -> p = p ; 
        front -> next = nullptr ; 
        rear = front ; 
    }
    else {
        if( rear -> p >= p ) {
            node* newNode = new( node ) ; 
            newNode -> info = i ; 
            newNode -> p = p ; 
            newNode -> next = nullptr ; 
            rear -> next = newNode ; 
            rear = newNode ; 
        }
        else if( p > front -> p ) {
            node* newNode = new( node ) ; 
            newNode -> next = front ; 
            newNode -> info = i ; 
            newNode -> p = p ; 
            front = newNode ; 
        }
        else {
            node* currentNode = front ;
            node* prevNode = front ; 
            while( currentNode -> p >= p ) {
                prevNode = currentNode ; 
                currentNode = currentNode -> next ; 
            }
            node* newNode = new( node ) ;
            newNode -> info = i ; 
            newNode -> p = p ;
            newNode -> next = currentNode ; 
            prevNode -> next = newNode ;
        }
    }
}

void Priority_Queue :: del(){
    node *temp;
    if(front == NULL) cout << "Queue Underflow";
    else{
        temp = front;
        cout << "Deleted item is : " << temp->info << endl;
        front = front->next;
        free(temp);
    }
}

void Priority_Queue :: show(){
    node *ptr;
    ptr = front;
    if(front == NULL) cout << "Queue is Empty";
    else{
        cout << "Queue is : " << endl;
        while(ptr != NULL){
            cout << "Priority : " << ptr->p << " Value : " << ptr->info << endl;
            ptr = ptr->next;
        }
    }
}

int main(){
    int c, info, p;
    Priority_Queue pq;
    while(true){
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> c;

        switch(c){
            case 1:
                cout << "Input the item value to be added in the queue : ";
                cin >> info;
                cout << "Input its priority : ";
                cin >> p;
                pq.insert(info, p);
                break;
            case 2:
                pq.del();
                break;
            case 3:
                pq.show();
                break;
            case 4:
                exit(1);
        }
    }
    return 0;
}