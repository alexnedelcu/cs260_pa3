#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <set>
#include <stack>
#include <sstream>
#include <string.h>

//Global defins
#define NP INT_MAX //No Path represents INFINITE COST
#define UNDEF -1 //Previous node is undefined in a path
using namespace std;

// -------  Representation of the graph in problem 6 --------- //
#define SIZE 6 //Number of nodes in the graph
//Adjacency matrix
int Adj[SIZE][SIZE] = {
	{ 0,  4,  1,  5,  8, 10},
	{NP,  0, NP, NP, NP, NP},
	{NP,  2,  0, NP, NP, NP},
	{NP, NP, NP,  0,  2, NP},
	{NP, NP, NP, NP,  0,  1},
	{NP, NP, NP, NP, NP,  0}
};
// ----------------------------------------------------------- //

//Starting node
int START;
//Cost MATRIX
int Cost[SIZE];
//Previous MATRIX
int  Prev[SIZE]; 
//Set for calculating U-S, which is unvisited nodes
set<int> s;

//Initisalize Cost and Previous matrices for a given SIZE
void init(){
	for(int i=0;i<SIZE;i++){
		Cost[i] = NP;
		Prev[i] = UNDEF;
	}
	s.clear();
}

// ------------ Printing functions ------------- //
//Print adjacency costs
void print_adj(){
	printf("Initial adjacency values:\n");
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			//Don't print out 'no path' valeus(INFINITE COST) or self paths
			if(Adj[i][j]!=NP && i!=j){
				printf("A[%d,%d]=%d  ",i+1,j+1,Adj[i][j]);
			}
		}	
	}
	cout<<"\n\n";	
}

//Used to print out D(cost) and P(prev)
char* d_p_string(){
	ostringstream ss;
	//Iterate over all nodes
	for(int i=0;i<SIZE;i++){
		//Dont print out the START node
		if(i!=START){
			//If there is no path, print something more meaningful that INT_MAX
			if(Cost[i]==NP)
				ss<<"-\t\t";
			else
				ss<<Cost[i]<<":"<<Prev[i]+1<<"\t\t";
		}
	}
	//Convert ostringstream to char*
	char* cstr = new char [ss.str().length()+1];
	strcpy(cstr, ss.str().c_str());
	return cstr;	
}
void print_shortest_paths(){
	cout<<"Shortest paths from "<<START+1<<":\n";
	int p;
	stack<int> path_stack;
	for(int i=0;i<SIZE;i++){
		if(i!=START && Prev[i]!=UNDEF){
			p=Prev[i];
			ostringstream ss;
			path_stack.push(i);
			path_stack.push(p);
			while(p!=START){
				p = Prev[p];
				path_stack.push(p);
			}
			//Pop the top off the stack to start the order listing
			cout<<path_stack.top()+1;
			path_stack.pop();
			while(!path_stack.empty()){
				cout<<"-"<<path_stack.top()+1;
				path_stack.pop();	
			}
			cout<<endl;
		}
	}
	cout<<endl;
}
// ------------ Printing functions ------------- //

//Given the value of START, set up Cost and Prev matrices
void initialize_cost(){
	for(int i=0;i<SIZE;i++){
		Cost[i] = Adj[START][i];
		//If there is no path, Prev is undefined
		if(Cost[i]==NP)
			Prev[i] = UNDEF;
		else
			Prev[i] = START;
	}
}

//Simple implementation of member wrapper around c++ built in set class
bool member(int n){
	return s.count(n)!=0;
}

//Returns index of node that has minimal cost that is NOT in set s
int find_min(){
	int n=-1; //min index
	int val=-1; //min val(initally -1 represents no min
	//iterate over U
	for(int i=0;i<SIZE;i++){
		//Ignore elements of s
		if(!member(i)){
			//If the new cost is smaller or the val is still -1(no min)
			if(Cost[i]<val || val==-1){
				n=i;
				val=Cost[i];
			}
		}
	}
	return n;
}

//returns min of (d1) and (d2+c2)
//If there is a new min, set P[v] to w
int min(int d1, int d2, int c2,int v, int w){
	//If either cost is infinite, return the old cost
	if(d2==NP || c2==NP){
		return d1;
	}
	//Check if the new cost is less
	if ((d2+c2)<d1){
		Prev[v] = w;
		return d2+c2;
	}
	return d1;
}

//Main Dijksta algorithm
void Dijksta(){
	s.clear();//Emtpy the set of visited nodes
	s.insert(START);//Put the START node in the set
	initialize_cost();
	//Print header with D[i] and P[i] for all i!=START
	cout<<"Iteration\tw\t";
	for(int i=0;i<SIZE;i++){
		if(i!=START)
			cout<<"D["<<i+1<<"]:P["<<i+1<<"]\t";
	}
	cout<<endl;
	//End Header
	printf("init\t\t-\t%s\n",d_p_string());
	//Dijksta algorithm
	for(int i=0;i<SIZE-1;i++){
		int w = find_min();
		for(int v=0;v<SIZE;v++){
			//Iterare over U-S
			if(!member(v)){
				Cost[v] = min(Cost[v],Cost[w],Adj[w][v], v, w);
			}
		}
		printf("%d\t\t%d\t%s\n",i+1,w+1,d_p_string());
		s.insert(w);
	}
}


int main(){
	init();
	print_adj();
	for (START=0;START<SIZE;START++){
	   Dijksta();
		print_shortest_paths();	
	}
	return 0;
}

