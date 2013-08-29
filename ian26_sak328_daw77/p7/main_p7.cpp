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

//Cost MATRIX
int Cost[SIZE][SIZE];
//Previous MATRIX
int  Prev[SIZE][SIZE]; 

//Initisalize Cost and Previous matrices for a given SIZE
void init(){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			Cost[i][j] = NP;
			Prev[i][j] = UNDEF;
		}
	}
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

void print_shortest_paths(){
	for(int START=0;START<SIZE;START++){
	cout<<"Shortest paths from "<<START+1<<":\n";
	int p;
	stack<int> path_stack;
	for(int i=0;i<SIZE;i++){
		if(i!=START && Prev[START][i]!=UNDEF){
			p=Prev[START][i];
			ostringstream ss;
			path_stack.push(i);
			path_stack.push(p);
			while(p!=START){
				p = Prev[START][p];
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
	}
	cout<<endl;
}
void print_cost_prev(){
	for(int i=0;i<SIZE;i++)
		cout<<"D["<<i+1<<"]:P["<<i+1<<"]\t";
	cout<<endl;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if (Cost[i][j]!=NP)
				cout<<Cost[i][j]<<":"<<Prev[i][j]+1<<"\t\t";
			else
				cout<<"-:-\t\t";
		}
		cout<<endl;
	}


}
// ------------ Printing functions ------------- //

//Given the value of Cost and Prev matrices
void initialize_cost(){
	for(int START=0;START<SIZE;START++){
		for(int i=0;i<SIZE;i++){
			Cost[START][i] = Adj[START][i];
			//If there is no path, Prev is undefined
			if(Cost[START][i]==NP)
				Prev[START][i] = UNDEF;
			else
				Prev[START][i] = START;
		}
	}
}

//Main Floyd algorithm
void Floyd(){
	initialize_cost();
	//Floyd algorithm
	for(int k=0;k<SIZE;k++){
	for(int i=0;i<SIZE;i++){
	for(int j=0;j<SIZE;j++){
		if( Cost[i][k]!=NP && Cost[k][j]!=NP && 
				(Cost[i][k]+Cost[k][j]<Cost[i][j])){
				Cost[i][j] = Cost[i][k] + Cost[k][j];
				Prev[i][j] = k;
		}
	}
	}
	}	
}



int main(){
	init();
	print_adj();
	Floyd();
	print_cost_prev();	
	print_shortest_paths();	
	return 0;
}

