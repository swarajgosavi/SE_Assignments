/*
Class : F3
Roll no : 21327
Assignment 1

Beginning with an empty binary tree construct binary tree by inserting the values in the order given.
After constructing the binary tree perform the following operations :
i. Display
   - In-Order
   - Pre-Order
   - Post-Order
ii. Change a tree so that the left and right pointers will be swapped at every node
iii. Find height of the tree
iv. Copy this tree to another tree
v. Count number of leaf nodes and number of internal nodes
vi. Erase or delete all the nodes in the binary tree
vii. Implement using both recursive and non-recursive functions

 */

#include<iostream>
#include<stack>

using namespace std;

class node{
private:
	char data;
	node *left;
	node *right;
public:
	node(){
		data = '\0';
		left = NULL;
		right = NULL;
	}
	node(char c){
		data = c;
		left = NULL;
		right = NULL;
	}
	friend class BT;
};

class BT{
private:
	node *root;
	stack<node*> s;
	int cleaf=0, cint=0;
public:
	BT(){
		root = NULL;
	}
	void create_BT();
	node* insert_node();
	void display();
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
	void swap_nodes(node*);
	node* get_root(){
		return root;
	}
	int height(node*);
	node* copy(node*);
	void leaf(node*);
	void count_leaf(){
		leaf(root);
		cout << "Number of leaf nodes : " << cleaf << endl;
		cint--;
		cout << "Number of internal nodes : " << cint << endl;
	}
	void delete_BT(node* p){
		if(p!=NULL){
			delete_BT(p->left);
			delete_BT(p->right);
			cout << "Deleted" << p->data << endl;
			delete(p);
		}
	}
};

void BT :: create_BT(){
	root = insert_node();
}

node* BT :: insert_node(){
	node* temp = new node;
	cout << "Data : ";
	cin >> temp->data;
	char ch;
	cout << "Enter right child? (Y/n) " << temp->data << " : ";
	cin >> ch;
	if(ch == 'Y' || ch == 'y')
		temp->right = insert_node();
	cout << "Enter left child? (Y/n) " << temp->data << " : ";
	cin >> ch;
	if(ch == 'Y' || ch == 'y')
		temp->left = insert_node();
	return temp;
}

void BT :: display(){
	cout << "\n\nInorder" << endl;
	inorder(root);

	cout << "\n\nPre-order" << endl;
	preorder(root);

	cout << "\n\nPost-order" << endl;
	postorder(root);
	cout << root->data;
}

void BT :: inorder(node* T){
	while(1){
		while(T!=NULL){
			s.push(T);
			T = T->left;
		}
		if(s.empty()) return;
		T = s.top();
		s.pop();
		cout << T->data << " ";
		T = T->right;
	}
}

void BT :: preorder(node* T){
	while(1){
		while(T!=NULL){
			cout << T->data << " ";
			if(T->right != NULL)
				s.push(T->right);
			T = T->left;
		}
		if(s.empty())
			return;
		T = s.top();
		s.pop();
	}
}

void BT :: postorder(node* T){
	node *temp;
	temp = new node('-1');
	while(1){
		while(T != NULL){
			s.push(T);
			if(T->right != NULL){
				s.push(T->right);
				s.push(temp);
			}
			T = T->left;
		}
		if(s.empty())
				return;
		T = s.top();
		s.pop();
		while(T != temp && !s.empty()){
			cout << T->data << " ";
			T = s.top();
			s.pop();
		}
		if(!s.empty()){
			T = s.top();
			s.pop();
		}
		if(s.empty())
			return;
	}
}

void BT :: swap_nodes(node* p){
	if(p){
		if(p->left || p->right){
			node *temp = p->left;
			p->left = p->right;
			p->right = temp;
		}
		swap_nodes(p->left);
		swap_nodes(p->right);
	}
}

int BT :: height(node* p){
	if(p == NULL) return 0;
	int left = height(p->left);
	int right = height(p->right);

	if(left > right) return left+1;
	else return right+1;
}

node* BT :: copy(node *p){
	node *q;
	if(p!=NULL){
		q = new node;
		q->data = p->data;
		if(p->left == NULL)
			q->left = NULL;
		else
			q->left = copy(p->left);
		if(p->right == NULL)
			q->right = NULL;
		else
			q->right = copy(p->right);
	}
	return q;
}

void BT :: leaf(node* p){
	if(p == NULL)
		return;
	if(p!=NULL){
		leaf(p->left);
		leaf(p->right);
		if(p->left == NULL && p->right == NULL)
			cleaf++;
		if(p->left != NULL || p->right != NULL)
			cint++;
	}
}

int main(){
	BT tree;
	tree.create_BT();
	tree.display();

	cout << "\n\nHeight is : " << tree.height(tree.get_root()) << endl;

	tree.count_leaf();

	node* n = tree.copy(tree.get_root());

	tree.swap_nodes(tree.get_root());
	cout << "\n\nTree nodes swapped : ";
	tree.display();

	tree.delete_BT(tree.get_root());
	cout << "Root deleted";

	tree.display();
	return 0;
}

/*
 * OUTPUT

              e
            /   \
           b     l
          / \   / \
         a   d o   m
        /
       s

Data : e
Enter right child? (Y/n) e : y
Data : l
Enter right child? (Y/n) l : y
Data : m
Enter right child? (Y/n) m : n
Enter left child? (Y/n) m : n
Enter left child? (Y/n) l : y
Data : o
Enter right child? (Y/n) o : n
Enter left child? (Y/n) o : n
Enter left child? (Y/n) e : y
Data : b
Enter right child? (Y/n) b : y
Data : d
Enter right child? (Y/n) d : n
Enter left child? (Y/n) d : n
Enter left child? (Y/n) b : y
Data : a
Enter right child? (Y/n) a : n
Enter left child? (Y/n) a : y
Data : s
Enter right child? (Y/n) s : n
Enter left child? (Y/n) s : n


Inorder
s a b d e o l m

Pre-order
e s a b d o l m

Post-order
s a b d o l m e

Tree nodes swapped :

Inorder
m l o e d b a s

Pre-order
e m l o d b a s

Post-order
m l o d b a s e
 */

