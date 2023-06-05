/*
Class : F3
Roll no : 21327
Assignment 1

Date of Performance : 13/02/2023
Date of Completion : 15/02/2023

Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
i. Insert new node,
ii. Find number of nodes in longest path from root,
iii. Minimum data value found in the tree,
iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
v. Search a value

                      20
                     /  \
                    /    \
                  10      30
                 / \     /  \
                5   15  25   40
               /
              3
 */

#include<iostream>

using namespace std;

// Class for Node
class node{
private:
	int data;
	node *left;
	node *right;
public:
	node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
	friend class BST;
};

// Class for Binary Search Tree and member functions
class BST{
private:
	node *root;
	int leafnode = 0, leaf[10];
public:
	BST(){
		root = NULL;
	}
	void create_bst(int);  // Function to create a BST
	void insert_bst(int);  // Function to insert a node in BST
	void display_bst();    // Function to display in-order, pre-order and post-order
	void inorder(node* temp){   // In-order
		if(temp == NULL) return;
		if(temp->left == NULL && temp->right == NULL){  // For counting the leaf nodes
			leaf[leafnode] = temp->data;
			leafnode++;
		}
		inorder(temp->left);
		cout << temp->data << " ";
		inorder(temp->right);
	}
	void preorder(node* temp){  // Pre_order
		if(temp == NULL) return;
		cout << temp->data << " ";
		preorder(temp->left);
		preorder(temp->right);
	}
	void postorder(node* temp){  // Post-order
		if(temp == NULL) return;
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data << " ";
	}
	int search_node(int);     // Function for searching a node
	void find_longpath();     // Function for finding the longest path
	void swap_data(node*);    // Function to swap data (i.e right node to left and vice versa)
	node* get_root(){         // Function to get root node
		return root;
	}
};

void BST :: create_bst(int d){
	node *temp = new node;
	temp->data = d;
	root = temp;
}

void BST :: insert_bst(int d){
	node *temp = root;
	node *t2 = new node;
	t2->data = d;
	while(temp != NULL){
		if(temp->data > d){
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
	cout << "\n\nPre-order" << endl;
	preorder(root);
	cout << "\n\nPost-order" << endl;
	postorder(root);
}

int BST :: search_node(int d){
	int level = 0;
	node *temp = root;
	while(temp != NULL){
		if(temp->data > d){
			temp = temp->left;
		}
		else if(temp->data < d){
			temp = temp->right;
		}
		else{
			cout << d << " Found at level : " << level << endl;
			return level;
		}
		level++;
	}
	if(temp == NULL){
		cout << d << " Not Found" << endl;
		return -1;
	}
	return 0;
}

void BST :: find_longpath(){
	int path[leafnode];
	cout << "\n\nLeaf node : " << leafnode << endl;
	for(int i=0; i<leafnode; i++){
		path[i] = search_node(leaf[i]);
	}
	int max = 0;
	for(int i=0; i<leafnode; i++){
		if(max <= path[i]) max = path[i];
	}
	cout << "\nLongest path is : " << max << endl;
}

void BST :: swap_data(node *p){
	if(p){
		if(p->left || p->right){
			node *temp = p->left;
			p->left = p->right;
			p->right = temp;
		}
		swap_data(p->left);
		swap_data(p->right);
	}
}

int main(){
	BST b;
	b.create_bst(20);  // Creation of BST
	b.insert_bst(10);  // Insert nodes
	b.insert_bst(5);
	b.insert_bst(3);
	b.insert_bst(15);
	b.insert_bst(30);
	b.insert_bst(25);
	b.insert_bst(40);

	b.display_bst();  // Display BST

	cout << "\n\n";
	b.search_node(20);  // Search nodes
	b.search_node(10);
	b.search_node(25);
	b.search_node(3);
	b.search_node(100);

	b.find_longpath();  // Finding the longest path

	b.swap_data(b.get_root());  // Swap data
	b.display_bst();            // Display swaped data
	return 0;
}

///*
// * OUTPUT
//
//Inorder
//3 5 10 15 20 25 30 40
//
//Pre-order
//20 10 5 3 15 30 25 40
//
//Post-order
//3 5 15 10 25 40 30 20
//
//20 Found at level : 0
//10 Found at level : 1
//25 Found at level : 2
//3 Found at level : 3
//100 Not Found
//
//
//Leaf node : 4
//3 Found at level : 3
//15 Found at level : 2
//25 Found at level : 2
//40 Found at level : 2
//
//Longest path is : 3
//
//Inorder
//40 30 25 20 15 10 5 3
//
//Pre-order
//20 30 40 25 10 15 5 3
//
//Post-order
//40 25 30 15 3 5 10 20
//*/
// */
