//======================================================================
// 
// Name : DSAL_PR-07_MSTGrah.cpp
// Author : Asst.Prof. Samadhan Jadhav
// Version :
// Copyright : Your copyright notice
// Description : MST of Graph using Prim’s Algorithm in C++.
//======================================================================

#include <iostream>
using namespace std;
//-------------------------------------------------------------
class DLLNode
{
public:
char data;
int cost;
DLLNode *down;
DLLNode *next;
}*Head;
//-------------------------------------------------------------
class Stack
{
public:
char vertex;
int in_stack(char node);
}stk[10];
int Stack :: in_stack(char node)
{
int i, present = 0;
for(i=0; i<10; i++)
{
if(stk[i].vertex == node)
present = 1;
}
return present;
}
//-------------------------------------------------------------
class Edges
{
public:
char src;
char dest;
int cost;
}edge[10];
//-------------------------------------------------------------
class Graph : public DLLNode, public Stack, public Edges
{
public:
DLLNode* create_Graph(DLLNode *head);
void display_Graph();
void find_MST();
};
//-------------------------------------------------------------
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
Newnode->cost = 0;
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
cout<<"\n\t\t Enter the cost from Vertex-"<<move->data<<": ";
cin>>Newnode->cost;
Newnode->next = NULL;
Newnode->down = NULL;
tmp->next = Newnode;
tmp = Newnode;
}
}
return head;
}
//-------------------------------------------------------------
void Graph :: display_Graph()
{
DLLNode *tmp, *move;
cout<<"\n Vertex :--> Adjacent Vertices";
move = Head;
while(move != NULL)
{
cout<<"\n "<<move->data<<" : ";
tmp = move->next;
while(tmp != NULL)
{
cout<<"-->"<<tmp->data<<"("<<tmp->cost<<")";
tmp = tmp->next;
}
cout<<"-->NULL";
move = move->down;
}
}
//-------------------------------------------------------------
void Graph :: find_MST()
{
int i, j, k, Cost;
char vertex, Source, Destination;
int top = -1;
int Vertices = 5;
int Total_cost = 0;
 DLLNode *tmp;
 tmp = Head; //......Add first Vertex into Stack
 if(!(in_stack(tmp->data)))
 {
 top++;
 stk[top].vertex = tmp->data;
 }
 while(top < Vertices-1) //....Untill All the Vertices are Not Visited
 {
 j = 0; //....for edge[]
 for(i=0; i<=top; i++) //....Check all the edges from Visited Vertices
 {
 vertex = stk[i].vertex;
 tmp = Head;
 while(vertex != tmp->data)
 tmp = tmp->down;
 Source = tmp->data; //....Current Vertex
 tmp = tmp->next;
 while(tmp != NULL) //....Check all adjacent vertices
 {
 Destination = tmp->data;
 if(!(in_stack(Destination))) //....If adjacent vertex is Not Visited
 {
 Cost = tmp->cost;
 edge[j].src = Source; //....Add Edge to the edge[]
 edge[j].dest = Destination;
 edge[j].cost = Cost;
 j++;
 }
 tmp = tmp->next;
 }
 }
 //.....Sort the edge[] Array
 Cost = 999;
 for(k=0; k<j; k++)
 {
 if(edge[k].cost < Cost)
 {
 Cost = edge[k].cost;
 Source = edge[k].src;
 Destination = edge[k].dest;
 }
 }
 //.....Display the edge with Minimum Cost
 cout<<"\n\n Added Edge in MST: "<<Source<<"--To--"<<Destination<<" Cost = "<<Cost;
 //....Add the cost of edge into Total_Cost
 Total_cost = Total_cost + Cost;
 //....Push the Next Vertex into Stack
 top++;
 stk[top].vertex = Destination;
 }
 cout<<"\n\n\t Total Cost = "<<Total_cost;
}
//-------------------------------------------------------------
int main()
{
Graph G1;
Head = NULL;
cout << "\n .......DSA Lab PR-07: MST in Graph........ ";
cout<<"\n\n------------------------------------------";
cout<<"\n Operation 01: Create Graph";
cout<<"\n------------------------------------------";
Head = G1.create_Graph(Head);
cout<<"\n\n------------------------------------------";
cout << "\n Operation 02: Display Graph";
cout<<"\n------------------------------------------";
G1.display_Graph();
cout<<"\n\n----------------------------------------------";
cout << "\n Operation 03: Find MST of Graph";
cout<<"\n----------------------------------------------";
G1.find_MST();
return 0;
}
//-------------------------------------------------------------
/*-----------OUTPUT-------------
.......DSA Lab PR-07: MST in Graph........ 
------------------------------------------
 Operation 01: Create Graph
------------------------------------------
How many vertices..? : 5
Enter name of Vertex: A
How many adjacent vertices.? : 3
Enter name of Adjacent Vertex: B
Enter the cost from Vertex-A: 4
Enter name of Adjacent Vertex: C
Enter the cost from Vertex-A: 6
Enter name of Adjacent Vertex: D
Enter the cost from Vertex-A: 2
Enter name of Vertex: B
How many adjacent vertices.? : 3
Enter name of Adjacent Vertex: A
Enter the cost from Vertex-B: 4
Enter name of Adjacent Vertex: C
Enter the cost from Vertex-B: 2
Enter name of Adjacent Vertex: E
Enter the cost from Vertex-B: 1
Enter name of Vertex: C
How many adjacent vertices.? : 4
Enter name of Adjacent Vertex: A
Enter the cost from Vertex-C: 6
Enter name of Adjacent Vertex: B
Enter the cost from Vertex-C: 2
Enter name of Adjacent Vertex: D
Enter the cost from Vertex-C: 3
Enter name of Adjacent Vertex: E
Enter the cost from Vertex-C: 4
Enter name of Vertex: D
How many adjacent vertices.? : 2
Enter name of Adjacent Vertex: A
Enter the cost from Vertex-D: 2
Enter name of Adjacent Vertex: C
Enter the cost from Vertex-D: 3
Enter name of Vertex: E
How many adjacent vertices.? : 2
Enter name of Adjacent Vertex: B
Enter the cost from Vertex-E: 1
Enter name of Adjacent Vertex: C
Enter the cost from Vertex-E: 4
------------------------------------------
 Operation 02: Display Graph
------------------------------------------
Vertex :--> Adjacent Vertices
A : -->B(4)-->C(6)-->D(2)-->NULL
B : -->A(4)-->C(2)-->E(1)-->NULL
C : -->A(6)-->B(2)-->D(3)-->E(4)-->NULL
D : -->A(2)-->C(3)-->NULL
E : -->B(1)-->C(4)-->NULL
----------------------------------------------
 Operation 03: Find MST of Graph
----------------------------------------------
Added Edge in MST: A--To--D Cost = 2
Added Edge in MST: D--To--C Cost = 3
Added Edge in MST: C--To--B Cost = 2
Added Edge in MST: B--To--E Cost = 1
Total Cost = 8

*/