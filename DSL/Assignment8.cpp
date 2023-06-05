#include<iostream>
#include<iomanip>

using namespace std;

int n=0;

class node{
public:
    int start, end, min, max, flag;
    node *next;
    node(){}
};

class sll{
private:
    node *head, *last;
public:
    sll(){
        head = NULL;
        last = NULL;
    }
    void createShedule();
    void displayShedule();
    void bookApp();
    void cancelApp();
    void sortApp();
};

void sll::createShedule(){
    node *temp;
    cout << "Enter the number of Appointment Slots: " ;
    cin >> n;
    for(int i=0; i<n; i++){
        temp = new node;
        cout << "Enter start time : " ;
        cin >> temp->start;
        cout << "Enter end time : " ;
        cin >> temp->end;
        cout << "Enter min time : " ;
        cin >> temp->min;
        cout << "Enter max time : " ;
        cin >> temp->max;
        temp->flag = 0;
        temp->next = NULL;
        
        if(head == NULL){
            head = temp;
            last = temp;
        }
        else{
            last->next = temp;
            last = last->next;
        }
    }
}

void sll::displayShedule(){
    int count = 0;
    cout << "\n\nAppointment Schedule" << endl;
    cout << setw(5) << "Sr.no" << setw(7) << "Start" << setw(7) << "End" << setw(8) << "Min_Dur" << setw(8) << "Max_Dur" << setw(8) << "Status" << endl;
    node *temp = head;
    while(temp != NULL){
        cout << setw(5) << count << setw(7) << temp->start << setw(7) << temp->end << setw(8) << temp->min << setw(8) << temp->max; 
        if(temp->flag == 1) cout << setw(8) << "Booked" << endl;
        else cout << setw(8) << "Free" << endl;
        temp = temp->next;
        count++;
    }
}

void sll::bookApp(){
    int start;
    cout << "\n\nPlease enter Appointment time to Book : ";
    cin >> start;
    node *temp = head;
    while(temp != NULL){
        if(start == temp->start){
            if(temp->flag == 0){
                cout << "Appointment Slot is Booked!!!!!" <<  endl;
                temp->flag = 1;
            }
            else
                cout << "Appointment Slot is not Available!!!" << endl;
        }
        temp = temp->next;
    }
}

void sll::cancelApp(){
    int start;
    cout << "\n\nPlease enter Appointment time to Cancel : ";
    cin >> start;
    node *temp = head;
    while(temp != NULL){
        if(start == temp->start){
            if(temp->flag == 1){
                cout << "Your Appoint Slot is Canceled!!!" << endl;
                temp->flag = 0;
            }
            else
                cout << "Your Appointment was not Booked!!!" << endl;
        }
        temp = temp->next;
    }
}

void sll::sortApp(){
    int val;
    for(int i=0; i<n; i++){
        node *temp = head;
        while(temp->next != NULL){
            if(temp->start > temp->next->start){
                val = temp->start;
                temp->start = temp->next->start;
                temp->next->start = val;

                val = temp->end;
                temp->end = temp->next->end;
                temp->next->end = val;

                val = temp->min;
                temp->min = temp->next->min;
                temp->next->min = val;

                val = temp->max;
                temp->max = temp->next->max;
                temp->next->max = val;

                val = temp->flag;
                temp->flag = temp->next->flag;
                temp->next->flag = val;
            }
            temp = temp->next;
        }
    }
}

int main(){
    sll list;
    bool f = true;
    list.createShedule();
    while(f){
        char ch;
        cout << "\nPlease select from the Menu : " << endl;
        cout << "1) Display free slots \n2) Book appointment \n3) Cancel appointment \n4) Exit\nChoice : ";
        cin >> ch;
        switch(ch){
        case '1':
            list.sortApp();
            list.displayShedule();
            break;
        case '2':
            list.bookApp();
            break;
        case '3':
            list.cancelApp();
            break;
        case '4':
            f = false;
            break;
        default:
            cout << "Please Enter a valid choice. ";
        }
    }
    return 0;
}