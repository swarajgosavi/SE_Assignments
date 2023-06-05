/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions: 
1. Operands and operator, both must be single character. 
2. Input Postfix expression must be in a desired format. 
3. Only '+', '-', '*' and '/ ' operators are expected.
*/

#include<iostream>

using namespace std;

const int MAX = 100;

template<class T>
class Stack{
private:
    T s[MAX];
    int top, result;
public:
    string post;
    Stack() { top = -1; }

    void push(T ch){
        if(!isFull()){
            top++;
            s[top] = ch;
        }
    }

    void pop(){
        if(!isEmpty()){
            T ch = s[top];
            top--;
        }
    }

    T popval(){
        if(!isEmpty()){
            T ch = s[top];
            top--;
            return ch;
        }
        else return 0;
    }

    bool isEmpty(){
        if(top == -1) return 1;
        else return 0;
    }

    bool isFull(){
        if(top == MAX-1) return 1;
        else return 0;
    }

    T stackTop(){
        return s[top];
    }

    void postfix(T expr[]);
    int pre(T);

    void eval();
    int operation(T, int, int);
};

template<class T>
void Stack<T> :: postfix(T expr[]){
    int j = 0, count = 0;
    while(expr[j] != '\0'){
        count++;
        j++;
    }

    for(int i=0; i<count; i++){
        T c = expr[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            post += c; 
        else if(c == '(') push(c);
        else if(c == ')') {
            while(s[top] != '('){
                post += s[top];
                pop();
            }
            pop();
        } 
        else if(c == '{') push(c);
        else if(c == '}') {
            while(s[top] != '{'){
                post += s[top];
                pop();
            }
            pop();
        } 
        else if(c == '[') push(c);
        else if(c == ']') {
            while(s[top] != '['){
                post += s[top];
                pop();
            }
            pop();
        }  
        else{
            while(!isEmpty() && pre(expr[i]) <= pre(s[top])){
                post += s[top];
                pop();
            }
            push(c);
        }
    }
    while(!isEmpty()){
        post += s[top];
        pop();
    }
    cout << "Postfix : " << post << endl;
}

template<class T>
int Stack<T> :: pre(T c){
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

template<class T>
void Stack<T> :: eval(){
    int j = 0, count = 0;
    while(post[j] != '\0'){
        count++;
        j++;
    }

    T c;
    for(int i=0; i<count; i++){
        c = post[i];
        if((c >= '0' && c <= '9'))
            push((int)c - 48);
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            int a = popval();
            int b = popval();
            result = operation(c, a, b);
            push(result);
        }
    }
    cout << "Answer = " << stackTop();
}

template<class T>
int Stack<T> :: operation(T op, int a, int b){
    switch(op){
    case '+':
        return a+b;
    case '-':
        return b-a;
    case '*':
        return a*b;
    case '/':
        return b/a;
    }
}

int main(){
    Stack<char> s1;
    char arr[MAX];
    string exp;
    int j=0;
    exp = "(5+2+(3-2)-1)*2/1";

    for(int i=0; i < 100; i++){
        arr[i] = exp[i];
    }

    cout << "Infix : " << exp << endl;
    s1.postfix(arr);
    
    Stack<int> s2;
    s2.post = s1.post;
    s2.eval();
    
    return 0;
}