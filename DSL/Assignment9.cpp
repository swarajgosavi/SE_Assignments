/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
Write C++ program using stack to check whether given expression is well parenthesized or not
*/

#include<iostream>

using namespace std;

const int MAX = 100;

class Stack{
private:
    int top;
    char s[MAX];
public:
    Stack(){ top = -1; }
    void push(char ch);
    char pop();
    bool isEmpty();
    bool isFull();
    bool checkParenthesis(char expr[]);
};

bool Stack::isEmpty(){
    if(top == -1) return 1;
    else return 0;
}

bool Stack :: isFull(){
    if(top == MAX-1) return 1;
    else return 0;
}

void Stack :: push(char ch){
    if(!isFull()){
        top++;
        s[top] = ch;
    }
}

char Stack :: pop(){
    if(!isEmpty()){
        char ch = s[top];
        top--;
        return ch;
    }
    else return '\0';
}

bool Stack :: checkParenthesis(char expr[]){
    int j = 0, count = 0;
    while(expr[j] != '\0'){
        count++;
        j++;
    }

    char x;
    for(int i=0; i < count; i++){
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
            push(expr[i]);
        }

        switch(expr[i]){
            case ')':
            x = pop();
            if(x == '[' || x == '{') return false;
            break;

            case ']':
            x = pop();
            if(x == '(' || x == '{') return false;
            break;

            case '}':
            x = pop();
            if(x == '[' || x == '(') return false;
            break;
        }
    }
    return(isEmpty());
}

int main(){
    Stack s1;
    string exp;
    char arr[MAX];

    exp = "{(2-5)+(2-5)+[3-5]}";

    for(int i=0; i < 100; i++){
        arr[i] = exp[i];
    }

    if(s1.checkParenthesis(arr)) cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl;

    return 0;
}