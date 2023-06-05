#include<iostream>
#include<string.h>

using namespace std;

class Node {
private:
	string key, value;
	Node* next;
public:
	Node(string key, string value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
	friend class sll;
};

class sll {
private:
	Node* head;
public:
	sll(){
		head = NULL;
	}
	void insert(string, string);
	void display();
	bool search(string);
	void delete_list(string);
};

class HashTable {
private:
	sll s;
public:
	void create_HT();
	void show_HT();
	int Hash(string);
	void insert_HT();
	void find();
	void delete_HT();
}HT[10];

void sll :: insert(string key, string value) {
	Node* temp = new Node(key, value);
	if(head == NULL){
		head = temp;
		return;
	}
	Node* t = head;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}

void sll :: display() {
	Node* temp = head;
	while(temp){
		cout << temp->key << " - " << temp->value;
		if(temp->next){
			cout << ", ";
		}else{
			cout << ".";
		}
		temp = temp->next;
	}
	cout << endl;
}

bool sll :: search(string word){
	Node* temp = head;
	while(temp != NULL){
		if(temp->key == word){
			cout << temp->key << " - " << temp->value;
			return true;
		}
		temp = temp->next;
	}
	cout << "\nWord Not Found 404";
	return false;
}

void sll :: delete_list(string word){
	if(search(word)){
		if( head -> key == word ) {
			Node* temp = head -> next ;
			delete head ;
			head = temp ;
		}
		else {
			Node* currentNode = head;
			Node* prevNode = NULL ;// Delete head node
			while( currentNode -> next != NULL ) {
				if( currentNode -> key == word ) {
					break ;
				}
				prevNode = currentNode ;
				currentNode = currentNode -> next ;
			}
			prevNode -> next = currentNode -> next ;
			delete currentNode ;
			cout << "\nDeleted word: " << word << endl ;
		}
	}
	else
		cout << endl << word << "Not present";
}

void HashTable :: show_HT() {
	int i, Tablesize = 10;
	cout << "\n\n ----Hash Table----";
	cout << "\n\n Word - Meaning" << endl;
	for(i=0; i<Tablesize; i++){
		cout << i << ". ";
		HT[i].s.display();
	}
}

int HashTable :: Hash(string nm) {
	int i, ascii = 0, Tablesize = 10;

	i = 0;
	while(nm[i] != '\0'){
		ascii += nm[i];
		i++;
	}
	return (ascii % Tablesize);
}

void HashTable :: insert_HT() {
	int i, cnt, index;
	string word, meaning;

	cout << "\n How many reords You wnat to insert? : ";
	cin >> cnt;

	for(i=0; i<cnt; i++){
		cout << "\nEnter Word : ";
		cin >> word;

		cout << "\nEnter Meaning of " << word << " : ";
		cin >> meaning;

		index = Hash(word);

		HT[index].s.insert(word, meaning);
	}
}

void HashTable :: find(){
	int index;
	string word;
	cout << "\nEnter Word to find : ";
	cin >> word;

	index = Hash(word);

	HT[index].s.search(word);
}

void HashTable :: delete_HT(){
	int index;
	string word;
	cout << "\nEnter Word to delete : ";
	cin >> word;

	index = Hash(word);

	HT[index].s.delete_list(word);
}

int main(){
	char ch;
	HashTable HT;

	while(1){
		cout << "\nMenu \n1. Display Dictionary \n2. Insert Word \n3. Search Word \n4. Delete Word \n5. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> ch;

		switch(ch){
		case '1':
			HT.show_HT();
			break;
		case '2':
			HT.insert_HT();
			break;
		case '3':
			HT.find();
			break;
		case '4':
			HT.delete_HT();
			break;
		case '5':
			cout << "Thank You !";
			return 0;
		default:
			cout << "Enter Valid Choice " << endl;
		}
	}


	return 0;
}
