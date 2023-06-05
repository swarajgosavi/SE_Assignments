#include<iostream>

using namespace std;

class node{
public:
    int data;
    node *prev;
    node *next;
    node(){}
    node(int n){
        this->data = n;
    }
};

class dll{
private:
    node *start, *last;
public:
    dll(){
        start = NULL;
        last = NULL;
    }
    void preparebinary(int n);
    void print();
    void onecomp();
    void twocomp();
    dll operator+(dll t);
    void insertBegin(int n);
};

void dll::preparebinary(int n){
    node *newnode = new node(n%2);
    start = last = newnode;
    n = n/2;
    while(n>0){
        node *temp = new node(n%2);
        start->prev = temp;
        temp->next = start;
        start = start->prev;
        n /= 2;
    }
}

void dll::print(){
    node *temp = start;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void dll::onecomp(){
    node *temp = start;
    while(temp != NULL){
        if(temp->data == 0) temp->data = 1;
        else temp->data = 0;
        temp = temp->next;
    }
}

void dll::twocomp(){
	// num1.onecomp();
	bool carry = 1;
	node *temp = last;
	while(temp != NULL){
		if(temp->data == 1 && carry == 1) temp->data = 0;
		else if(temp->data == 0 && carry == 1){
			temp->data = 1;
			carry = 0;
		}
		if(carry == 0){
			break;
		}
		temp = temp->prev;
	}
}

dll dll::operator+(dll t){
	dll sum;
	node *a = last;
	node *b = t.last;
	int carry = 0;
	while(a != NULL && b != NULL){
		int add = (a->data)^(b->data)^carry;
		sum.insertBegin(add);
		carry = (a->data & b->data) | (a->data & carry) | (b->data & carry);
		a = a->prev;
		b = b->prev;
	}
	while(a != NULL){
		int add = a->data ^ carry;
		sum.insertBegin(add);
		carry = a->data & carry;
		a = a->prev;
	}
	while(b != NULL){
		int add = b->data ^ carry;
		sum.insertBegin(add);
		carry = b->data & carry;
		b = b->prev;
	}
	if(carry == 1){
		sum.insertBegin(1);
	}
	return sum;
}

void dll::insertBegin(int n){
	node *temp = new node(n);
	if(start == NULL){
		start = last = temp;
	}
	else{
		start->prev = temp;
        temp->next = start;
        start = start->prev;
	}
}

int main(){
    dll num1;
    num1.preparebinary(24);

    cout << "Num1 : ";
    num1.print();

    num1.onecomp();
    cout << "1's Complement: ";
    num1.print();

    num1.twocomp();
    cout << "2's Complement: ";
    num1.print();


    dll num2;
    
    num2.preparebinary(15);
    cout << "Num2 : ";
    num2.print();

    num2.onecomp();
    cout << "1's Complement: ";
    num2.print();

    num2.twocomp();
    cout << "2's Complement: ";
    num2.print();


    dll num3;
    // num3.preparebinary(9);
    num1.preparebinary(24);
    num2.preparebinary(15);
    num3 = num1 + num2;
    cout << " + ";
    num3.print();

    return 0;
}