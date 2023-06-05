#include<iostream>
using namespace std;


class node{
private:
	int key, freq;
	node *left;
	node *right;
public:
	node(){
		key = freq = 0;
		left = NULL;
		right = NULL;
	}
	friend class BST;
};

class BST{
private:
	node *root;
public:
	BST(){
		root = NULL;
	}
	void create_bst(int, int);  // Function to create a BST
	void insert_bst(int, int);  // Function to insert a node in BST
	void display_bst();    // Function to display in-order, pre-order and post-order
	void inorder(node* temp){   // In-order
		if(temp == NULL) return;
		inorder(temp->left);
		cout << temp->key << "(" << temp->freq << ") ";
		inorder(temp->right);
	}
	node* get_root(){         // Function to get root node
		return root;
	}
    void mincost();
};

void BST :: create_bst(int d, int f){
	node *temp = new node;
	temp->key = d;
    temp->freq = f;
	root = temp;
}

void BST :: insert_bst(int d, int f){
	node *temp = root;
	node *t2 = new node;
	t2->key = d;
    t2->freq = f;
	while(temp != NULL){
		if(temp->key > d){
			if(temp->left == NULL){
				temp->left = t2;
				break;
			}
			else{
				temp = temp->left;
			}
		}
		else{
			if(temp->right == NULL){
				temp->right = t2;
				break;
			}
			else{
				temp = temp->right;
			}
		}
	}
}

void BST :: display_bst(){
	cout << "\nInorder" << endl;
	inorder(root);
}

void BST :: mincost() {
    node *temp = root;
    node *queue[3];
    queue[0] = temp;
    queue[1] = temp->left;
    queue[2] = temp->right;
    cout << "\nmin cost is : " << temp->freq + 2*(temp->left->freq+temp->right->freq) << endl;
}

int main() {
    BST tree;

    tree.create_bst(20,12);
    tree.insert_bst(10,11);
    tree.insert_bst(30,10);
    tree.display_bst();

    tree.mincost();
    return 0;
}
