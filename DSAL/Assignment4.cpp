		//................Header Files
#include <iostream>
#include<string.h>
using namespace std;

//.......................Class Definition
class HashTable
{
	char Cname[20];
	int telephone;
public:
	void create_HT();
	void show_HT();
	int Hash(char nm[]);
	void insert_HT1();
	void insert_HT2();
	void search_HT1();
	void search_HT2();

}HT1[10], HT2[10];

//..................................Member Function Definition

void HashTable :: create_HT()
{
	int i, Tablesize = 10;
	for(i=0; i < Tablesize; i++)
	{
		strcpy(HT1[i].Cname , "----");
		HT1[i].telephone = 0;

		strcpy(HT2[i].Cname , "----");
		HT2[i].telephone = 0;
	}
}


void HashTable :: show_HT()
{
	int i, Tablesize = 10;

	cout<<"\n\n ----Hash Table-01---       ---Hash Table-02---";
	cout<<"\n\n Index Cname-Telephone    Index Cname-Telephone";
	for(i=0; i < Tablesize; i++)
	{
		cout<<"\n  "<<i<<"\t"<<HT1[i].Cname<<"\t"<<HT1[i].telephone;
		cout<<"\t  "<<i<<"\t"<<HT2[i].Cname<<"\t"<<HT2[i].telephone;
	}

}

int HashTable :: Hash(char nm[])
{
	int i, askii = 0;
	int Tablesize = 10;

	for(i=0; nm[i]!='\0'; i++)
	{
		askii = askii + nm[i];
	}
	return (askii % Tablesize);
}


void HashTable :: insert_HT1()
{
	int i, cnt, tele, index, Tablesize = 10;
	char name[20];

	cout<<"\n How many records u wanna insert..?: ";
	cin>>cnt;

	for(i=0; i < cnt; i++)
	{
		cout<<"\n\t Enter Client Name: ";
		cin>>name;

		cout<<"\n\t Enter Telephone No: ";
		cin>>tele;

		index = Hash(name);

		if(HT1[index].telephone == 0)
		{
			strcpy(HT1[index].Cname , name);
			HT1[index].telephone = tele;
		}
		else
		{
			do
			{
				index = ((index + 1) % Tablesize);
			}while(HT1[index].telephone != 0);

			strcpy(HT1[index].Cname , name);
			HT1[index].telephone = tele;
		}
	}
}

void HashTable :: insert_HT2()
{
	int i, cnt, tele, index, Tablesize = 10;
	char name[20];
	int Act_Index, Cur_Index, New_Index;

	cout<<"\n How many records u wanna insert..?: ";
	cin>>cnt;

	for(i=0; i < cnt; i++)
	{
		cout<<"\n\t Enter Client Name: ";
		cin>>name;

		cout<<"\n\t Enter Telephone No: ";
		cin>>tele;

		index = Hash(name);

		if(HT2[index].telephone == 0)
		{
			strcpy(HT2[index].Cname , name);
			HT2[index].telephone = tele;
		}
		else
		{
			Cur_Index = index;
			Act_Index = Hash(HT2[index].Cname);
			do
			{
				index = ((index + 1) % Tablesize);
			}while(HT2[index].telephone != 0);
			New_Index = index;

			if(Act_Index == Cur_Index)
			{
				strcpy(HT2[New_Index].Cname , name);
				HT2[New_Index].telephone = tele;
			}
			else
			{
				strcpy(HT2[New_Index].Cname , HT2[Cur_Index].Cname);
				HT2[New_Index].telephone = HT2[Cur_Index].telephone;

				strcpy(HT2[Cur_Index].Cname , name);
				HT2[Cur_Index].telephone = tele;
			}

		}
	}
}

void HashTable :: search_HT1()
{
	int i, cnt, comp, cmp, index, Tablesize = 10;
	char name[20];

	comp = 0;

	cout<<"\n How many records u wanna search..?: ";
	cin>>cnt;

	for(i=0; i < cnt; i++)
	{
		cmp = 0;

		cout<<"\n\t Enter Client Name: ";
		cin>>name;

		index = Hash(name);

		if(strcmp(HT1[index].Cname , name) == 0)
		{
			cmp++;
			cout<<"\n Client's Telephone No: "<<HT1[index].telephone;
		}
		else
		{
			cmp++;
			do
			{
				index = ((index + 1) % Tablesize);
				cmp++;
			}while(strcmp(HT1[index].Cname , name) != 0);

			cout<<"\n Client's Telephone No: "<<HT1[index].telephone;
		}
		cout<<"\n Needed Comparisons: "<<cmp;
		comp = comp + cmp;
	}
	cout<<"\n Total Needed Comparisons: "<<comp;

}

void HashTable :: search_HT2()
{
	int i, cnt, comp, cmp, index, Tablesize = 10;
	char name[20];

	comp = 0;

	cout<<"\n How many records u wanna search..?: ";
	cin>>cnt;

	for(i=0; i < cnt; i++)
	{
		cmp = 0;
		cout<<"\n\t Enter Client Name: ";
		cin>>name;

		index = Hash(name);

		if(strcmp(HT2[index].Cname , name) == 0)
		{
			cmp++;
			cout<<"\n Client's Telephone No: "<<HT2[index].telephone;
		}
		else
		{
			cmp++;
			do
			{
				index = ((index + 1) % Tablesize);
				cmp++;
			}while(strcmp(HT2[index].Cname , name) != 0);

			cout<<"\n Client's Telephone No: "<<HT2[index].telephone;
		}

		cout<<"\n Needed Comparisons: "<<cmp;
		comp = comp + cmp;
	}
	cout<<"\n Total Needed Comparisons: "<<comp;
}



int main()
{
	cout<<"\n -----****DSA Lab PR-04 Hash Table****-----";

	HashTable HT;

	cout<<"\n A] Creating Hash Table.........";
	HT.create_HT();

	cout<<"\n B] Display Hash Table.........";
	HT.show_HT();

	cout<<"\n C] Insert (Cname-telephone) in Hash Table-01.........";
	HT.insert_HT1();

	cout<<"\n D] Insert (Cname-telephone) in Hash Table-02.........";
	HT.insert_HT2();

	cout<<"\n E] Display Hash Table.........";
	HT.show_HT();

	cout<<"\n F] Search in Hash Table-01.........";
	HT.search_HT1();

	cout<<"\n G] Search in Hash Table-02.........";
	HT.search_HT2();

	return 0;
}

/*
 -----****DSA Lab PR-04 Hash Table****-----

 A] Creating Hash Table.........

 B] Display Hash Table.........

 ----Hash Table-01---       ---Hash Table-02---

 Index Cname-Telephone    Index Cname-Telephone
  0	----		0	  	0	----	0
  1	----		0	  	1	----	0
  2	----		0	  	2	----	0
  3	----		0	  	3	----	0
  4	----		0	  	4	----	0
  5	----		0	  	5	----	0
  6	----		0	  	6	----	0
  7	----		0	  	7	----	0
  8	----		0	  	8	----	0
  9	----		0	  	9	----	0


 C] Insert (Cname-telephone) in Hash Table-01.........
 How many records u wanna insert..?: 5

	 Enter Client Name: abc

	 Enter Telephone No: 111

	 Enter Client Name: bca

	 Enter Telephone No: 222

	 Enter Client Name: xyz

	 Enter Telephone No: 333

	 Enter Client Name: yzx

	 Enter Telephone No: 444

	 Enter Client Name: abd

	 Enter Telephone No: 555



 D] Insert (Cname-telephone) in Hash Table-02.........
 How many records u wanna insert..?: 5

	 Enter Client Name: abc

	 Enter Telephone No: 111

	 Enter Client Name: bca

	 Enter Telephone No: 222

	 Enter Client Name: xyz

	 Enter Telephone No: 333

	 Enter Client Name: yzx

	 Enter Telephone No: 444

	 Enter Client Name: abd

	 Enter Telephone No: 555


 E] Display Hash Table.........

 ----Hash Table-01---       ---Hash Table-02---

 Index Cname-Telephone    Index Cname-Telephone
  0	----		0	  	0	----	0
  1	----		0	  	1	----	0
  2	----		0	  	2	----	0
  3	xyz		333	  	3	xyz	333
  4	abc		111	  	4	abc	111
  5	bca		222	  	5	abd	555
  6	yzx		444	  	6	yzx	444
  7	abd		555	  	7	bca	222
  8	----		0	  	8	----	0
  9	----		0	  	9	----	0


 F] Search in Hash Table-01.........
 How many records u wanna search..?: 3

	 Enter Client Name: abc

 Client's Telephone No: 111
 Needed Comparisons: 1
	 Enter Client Name: yzx

 Client's Telephone No: 444
 Needed Comparisons: 4
	 Enter Client Name: abd

 Client's Telephone No: 555
 Needed Comparisons: 3

 Total Needed Comparisons: 8

 G] Search in Hash Table-02.........
 How many records u wanna search..?: 3

	 Enter Client Name: abc

 Client's Telephone No: 111
 Needed Comparisons: 1
	 Enter Client Name: yzx

 Client's Telephone No: 444
 Needed Comparisons: 4
	 Enter Client Name: abd

 Client's Telephone No: 555
 Needed Comparisons: 1

 Total Needed Comparisons: 6

 */
