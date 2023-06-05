/*
Assignment 12
Name : Swaraj Sachin Gosavi
Roll no : 21327
Batch : F3 [SE 3]

Write  a  program  in  C++  to  use  map  associative  container.  
The  keys  will  be  the names  of  states  and  the  values  will  be  the  populations  of  the  states.  When the program  runs,  the  user  is  prompted  to  type  the  name  of  a  state.  
The  program  then looks in the map, using the state name as an index and returns the population of thestate
*/

#include<iostream>
#include<map>
#include<iomanip>

using namespace std;

typedef map<string, int> populationMap;

int main(){
    string state;
    int popu;
    populationMap population;

    cout << "Enter three sets of State and Population \n";

    for(int i=0; i<3; i++){
        cout << "State : ";
        cin >> state;
        cout << "Population in Millions : ";
        cin >> popu;
        population[state] = popu;
    }

    population["Maharashtra"] = 112;
    
    population.insert(pair<string, int> ("Gujarat", 60));
    int n = population.size();
    cout << "\nSize of Map: " << n << endl;
    cout << "List of State Populations\n";

    populationMap :: iterator p;
    for(p=population.begin(); p!=population.end(); p++){
        cout << setiosflags(ios::left) << setw(15) << p->first << setw(5) << p->second << " Millions" << endl;
    }

    cout << "\nEnter State: ";
    cin >> state;
    popu = population[state];

    cout << "\nPopulation of " << state << " is " << popu << " Millions";
    return 0;
}