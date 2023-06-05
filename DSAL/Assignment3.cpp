/*
 * Assignment3.cpp
 *
 *  Created on: 01-Mar-2023
 *      Author: pict
 */
#include<iostream>

using namespace std;

class TBSTNode{
private:
	int data;
	TBSTNode *left, *right;
	bool Rthread;
public:
	TBSTNode(){
		this->data = -1;
		left = NULL;
		right = NULL;
		Rthread = false;
	}
	TBSTNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
		Rthread = false;
	}
	friend class TBST;
};

class TBST{
private:
	TBSTNode *root;
public:
	TBST(){
		root = NULL;
	}
	void create(int);
	void insert(int, TBSTNode*);
	void display();
	TBSTNode* get_root(){return root;}
	void inorder(TBSTNode*);
};

void TBST :: create(int data){
	root = new TBSTNode(data);
}

void TBST :: insert(int data, TBSTNode *root){
	TBSTNode *newnode = new TBSTNode(data), *parent = root;
	if(newnode->data < parent->data){
		if(parent->left == NULL){
			parent->left = newnode;
			newnode->right = parent;
			newnode->Rthread = true;
		}
		else insert(data, parent->left);
	}

	if(newnode->data > parent->data){
		if(parent->right == NULL || parent->Rthread){
			newnode->Rthread = parent->Rthread;
			newnode->right = parent->right;
			parent->right = newnode;
			parent->Rthread = false;
		}
		else insert(data, parent->right);
	}
}

void TBST :: inorder(TBSTNode* temp){
	while(!temp->Rthread) temp = temp->left;

	while(temp){
		cout << temp->data << " ";
		temp = temp->right;
	}
}

int main(){
	TBST tree;

	tree.create(50);
	tree.insert(30, tree.get_root());
	tree.insert(70, tree.get_root());
	tree.insert(9, tree.get_root());
	tree.insert(48, tree.get_root());
	tree.insert(62, tree.get_root());
	tree.insert(91, tree.get_root());

	tree.inorder(tree.get_root());

	return 0;
}
