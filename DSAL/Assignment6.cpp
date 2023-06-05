/*
Class : F3
Roll no : 21327
Assignment 1

Date of Performance : /04/2023
Date of Completion : /04/2023

Represent a given graph using adjacency list to perform DFS and BFS.
Use the map of the area around the college as the graph. Identify the
prominent landmarks as nodes and perform DFS and BFS on that.

 */


#include <iostream>
#include <string.h>
using namespace std;

class DLLNode
{
public:
	char data[10];
	DLLNode *down;
	DLLNode *next;
}*Head;

class Stack
{
public:
	char vertex[10];
	int in_stack(char node[]);

}stk[10];

int Stack :: in_stack(char node[])
{
	int i, present = 0;
	for(i=0; i<10; i++)
	{
		if(strcmp(stk[i].vertex , node) == 0)
			present = 1;
	}
	return present;
}

class Queue
{
public:
	char vertex[10];
	int in_Queue(char node[]);

}que[10];

int Queue :: in_Queue(char node[])
{
	int i, present = 0;
	for(i=0; i<10; i++)
	{
		if(strcmp(que[i].vertex , node) == 0)
			present = 1;
	}
	return present;
}


class Graph : public DLLNode, public Stack, public Queue
{
public:
	DLLNode* create_Graph(DLLNode *head);
	void display_Graph();
	void traverse_DFS();
	void traverse_BFS();
	void is_Connected();
	void check_degree();
};

DLLNode* Graph :: create_Graph(DLLNode *head)
{
	int i, j, vertices, adjacent;
	DLLNode *tmp, *move, *Newnode;

	cout<<"\n\t How many vertices..? : ";
	cin>>vertices;

	for(i=0; i<vertices; i++)
	{
		Newnode = new DLLNode;

		cout<<"\n\t Enter name of Vertex: ";
		cin>>Newnode->data;
		Newnode->next = NULL;
		Newnode->down = NULL;

		if(head == NULL)
		{
			head = Newnode;
			move = tmp = head;
		}
		else
		{
			move->down = Newnode;
			move = move->down;
			tmp = move;
		}

		cout<<"\n\t How many adjacent vertices.? : ";
		cin>>adjacent;

		for(j=0; j<adjacent; j++)
		{
			Newnode = new DLLNode;

			cout<<"\n\t\t Enter name of Adjacent Vertex: ";
			cin>>Newnode->data;
			Newnode->next = NULL;
			Newnode->down = NULL;

			tmp->next = Newnode;
			tmp = Newnode;
		}
	}
	return head;
}

void Graph :: display_Graph()
{
	DLLNode *tmp, *move;

	cout<<"\n\n Vertex :--> Adjacent Vertices....";
	move = Head;
	while(move != NULL)
	{
		cout<<"\n"<<move->data<<" : ";
		tmp = move->next;
		while(tmp != NULL)
		{
			cout<<"-->"<<tmp->data;
			tmp = tmp->next;
		}
		move = move->down;
	}
}

void Graph :: traverse_DFS()
{
	DLLNode *tmp;
	int done, top = -1;

	tmp = Head;
	if(!(in_stack(tmp->data)))
	{
		top++;
		strcpy(stk[top].vertex , tmp->data);
		cout<<"DFS: "<<stk[top].vertex;

		while(top != -1)
		{
			tmp = Head;
			while(strcmp(stk[top].vertex , tmp->data) != 0)
				tmp = tmp->down;

			tmp = tmp->next;
			done = 0;

			while(tmp != NULL && done == 0)
			{

				if(!(in_stack(tmp->data)))
				{
					top++;
					strcpy(stk[top].vertex , tmp->data);

					cout<<", "<<stk[top].vertex;

					done = 1;
				}
				else
					tmp = tmp->next;
			}
			if(tmp == NULL)
				top--;

		}
	}
	else
	{
		cout<<"\n\t Can not start DFS from Vertex: "<<tmp->data;
	}


}


void Graph :: traverse_BFS()
{
	DLLNode *tmp;
	int front, rear;
	front = rear = -1;

	tmp = Head;
	if(!(in_Queue(tmp->data)))
	{
		rear++;
		strcpy(que[rear].vertex , tmp->data);

		cout<<"BFS: "<<que[rear].vertex;

		while(front != rear)
		{
			tmp = Head;
			front++;
			while(strcmp(que[front].vertex , tmp->data) != 0)
					tmp = tmp->down;

			tmp = tmp->next;

			while(tmp != NULL)
			{

				if(!(in_Queue(tmp->data)))
				{
					rear++;
					strcpy(que[rear].vertex , tmp->data);

					cout<<", "<<que[rear].vertex;
				}
				else
					tmp = tmp->next;
			}
		}
	}
	else
	{
		cout<<"\n\t Can not start DFS from Vertex: "<<tmp->data;
	}
}

void Graph :: is_Connected()
{

}

void Graph :: check_degree()
{
	DLLNode *tmp, *move;
	int cnt, flag = 0;

	cout<<"\n\n Vertex : Degree....";

	move = Head;
	while(move != NULL)
	{
		cout<<"\n"<<move->data<<" : ";

		tmp = move->next;
		cnt = 0;

		while(tmp != NULL)
		{
			cnt++;
			tmp = tmp->next;
		}
		cout<<" "<<cnt;
		if(cnt == 0)
			flag = 1;
		move = move->down;
	}
	if(flag == 0)
		cout<<"\n\n As all Vertices has Degree > 0, the Graph is Connected.";
	else
		cout<<"\n\n As some Vertices has Degree = 0, the Graph is Disconnected.";
}


int main()
{
	Graph G1;
	Head = NULL;

	cout << "\n .......DSA Lab PR-06: Graph........ ";

	cout << "\n\n Operation 01: Create Graph..........";
	Head = G1.create_Graph(Head);

	cout << "\n\n Operation 02: Display Graph..........";
	G1.display_Graph();

	cout << "\n\n Operation 03: DFS Traversal of Graph..........";
	G1.traverse_DFS();

	cout << "\n\n Operation 04: BFS Traversal of Graph..........";
	G1.traverse_BFS();

	cout << "\n\n Operation 06: Degrees of Vertices in the Graph..........";
	G1.check_degree();

	return 0;
}

/*--------OUTPUT----------
 *
  .......DSA Lab PR-06: Graph........

 Operation 01: Create Graph..........
	 How many vertices..? : 5

	 Enter name of Vertex: PICT

	 How many adjacent vertices.? : 3

		 Enter name of Adjacent Vertex: BHARATI

		 Enter name of Adjacent Vertex: KATRAJ

		 Enter name of Adjacent Vertex: SKNCOE

	 Enter name of Vertex: BHARATI

	 How many adjacent vertices.? : 3

		 Enter name of Adjacent Vertex: PICT

		 Enter name of Adjacent Vertex: KATRAJ

		 Enter name of Adjacent Vertex: TEMPLE

	 Enter name of Vertex: KATRAJ

	 How many adjacent vertices.? : 3

		 Enter name of Adjacent Vertex: PICT

		 Enter name of Adjacent Vertex: BHARATI

		 Enter name of Adjacent Vertex: TEMPLE

	 Enter name of Vertex: TEMPLE

	 How many adjacent vertices.? : 3

		 Enter name of Adjacent Vertex: KATRAJ

		 Enter name of Adjacent Vertex: BHARATI

		 Enter name of Adjacent Vertex: SKNCOE

	 Enter name of Vertex: SKNCOE

	 How many adjacent vertices.? : 2

		 Enter name of Adjacent Vertex: PICT

		 Enter name of Adjacent Vertex: TEMPLE


 Operation 02: Display Graph..........

 Vertex :--> Adjacent Vertices....

PICT : -->BHARATI-->KATRAJ-->SKNCOE
BHARATI : -->PICT-->KATRAJ-->TEMPLE
KATRAJ : -->PICT-->BHARATI-->TEMPLE
TEMPLE : -->KATRAJ-->BHARATI-->SKNCOE
SKNCOE : -->PICT-->TEMPLE

 Operation 03: DFS Traversal of Graph..........

DFS: PICT, BHARATI, KATRAJ, TEMPLE, SKNCOE

 Operation 04: BFS Traversal of Graph..........

BFS: PICT, BHARATI, KATRAJ, SKNCOE, TEMPLE

 Operation 06: Degrees of Vertices in the Graph..........

 Vertex : Degree....
   PICT :  3
BHARATI :  3
 KATRAJ :  3
 TEMPLE :  3
 SKNCOE :  2

 As all Vertices has Degree > 0, the Graph is Connected.

*/
