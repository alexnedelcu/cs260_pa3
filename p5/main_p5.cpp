#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <set>
#include <stack>
#include <sstream>
#include <string.h>

#define NP INT_MAX //No Path represented with "infiniy"
#define UNDEF -1
#define SIZE 6

using namespace std;

//Adjacency matrix
int Adj[SIZE][SIZE] = {
	{ 0,  4,  1,  5,  8, 10},
	{NP,  0, NP, NP, NP, NP},
	{NP,  2,  0, NP, NP, NP},
	{NP, NP, NP,  0,  2, NP},
	{NP, NP, NP, NP,  0,  1},
	{NP, NP, NP, NP, NP,  0}
};
//Starting node
int START = 0;
//Cost MATRIX
int Cost[SIZE] = {NP,NP,NP,NP,NP,NP};
//Previous
int  Prev[SIZE] = {UNDEF,UNDEF,UNDEF,UNDEF,UNDEF,UNDEF};
//Set
set<int> s;

void print_initial_adj(){
	printf("Initial adjacency values:\n");
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(Adj[i][j]!=NP && Adj[i][j]!=0){
				printf("A[%d,%d]=%d  ",i+1,j+1,Adj[i][j]);
			}
		}	
	}
	cout<<"\n\n";	
}
//Used to print out D(cost) and P(prev)
char* d_p_string(){
	ostringstream ss;
	for(int i=0;i<SIZE;i++){
		if(i!=START){
			if(Cost[i]==NP)
				ss<<"-\t\t";
			else
				ss<<Cost[i]<<":"<<Prev[i]+1<<"\t\t";
		}
	}
	char* cstr = new char [ss.str().length()+1];
	strcpy(cstr, ss.str().c_str());
	return cstr;	
}

void initialize_cost(){
	for(int i=0;i<SIZE;i++){
		Cost[i] = Adj[START][i];
		if(Cost[i]==NP)
			Prev[i] = UNDEF;
		else
			Prev[i] = START;
	}
}

bool member(int n){
	return s.count(n)!=0;
}

int find_min(){
	int n=-1; //min index
	int val=-1; //min val
	for(int i=0;i<SIZE;i++){
		if(!member(i)){
			if(Cost[i]<val || val==-1){
				n=i;
				val=Cost[i];
			}
		}
	}
	return n;
}

//returns min of (d1) and (d2+c2)
//If theree is a new min, set P[v] to w
int min(int d1, int d2, int c2,int v, int w){
	if(d2==INT_MAX || c2==INT_MAX){
		return d1;
	}
	if ((d2+c2)<d1){
		Prev[v] = w;
		return d2+c2;
	}
	return d1;

}

void Dijksta(){
	s.clear();
	initialize_cost();
	s.insert(START);
	cout<<"Iteration\tw\t";
	for(int i=0;i<SIZE;i++){
		if(i!=START)
			cout<<"D["<<i+1<<"]:P["<<i+1<<"]\t";
	}
	cout<<endl;
	printf("init\t\t-\t%s\n",d_p_string());
	for(int i=0;i<SIZE-1;i++){
		int w = find_min();
		for(int v=0;v<SIZE;v++){
			if(!member(v)){
				Cost[v] = min(Cost[v],Cost[w],Adj[w][v], v, w);
			}
		}
		printf("%d\t\t%d\t%s\n",i,w+1,d_p_string());
		s.insert(w);
	}
	
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

int main(){
	print_initial_adj();
	for (START=0;START<SIZE;START++){
	   Dijksta();
		print_shortest_paths();	
	}
	return 0;
}

