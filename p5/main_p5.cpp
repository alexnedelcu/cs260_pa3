#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <set>
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
int START = 1;
//Cost MATRIX
int Cost[SIZE] = {NP,NP,NP,NP,NP,NP};
//Previous
int  Prev[SIZE] = {UNDEF};
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
	ostringstream s;
	for(int i=0;i<SIZE;i++){
		if(i+1!=START){
			if(Cost[i]==NP)
				s<<"-\t\t";
			else
				s<<Cost[i]<<":"<<Prev[i]<<"\t\t";
		}
	}
	char* cstr = new char [s.str().length()+1];
	strcpy(cstr, s.str().c_str());
	return cstr;	
}

void initialize_cost(int s){
	for(int i=0;i<SIZE;i++){
		Cost[i] = Adj[s-1][i];
		if(Cost[i]==NP)
			Prev[i] = UNDEF;
		else
			Prev[i] = s;
	}
}

bool member(int n){
	return s.count(n)!=0;
}

int find_min(){
	int n=-1; //min index
	int val=-1; //min val
	for(int i=0;i<SIZE;i++){
		if(!member(i+1)){
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
		Prev[v] = w+1;
		return d2+c2;
	}
	return d1;

}

void Dijksta(){
	s.clear();
	initialize_cost(START);
	s.insert(START);
	cout<<"Iteration\tw\tD[2]:P[2]\tD[3]:P[3]\tD[4]:P[4]\tD[5]:P[5]\tD[6]:P[6]\n";
	printf("init\t\t-\t%s\n",d_p_string());
	for(int i=0;i<SIZE-1;i++){
		int w = find_min();
		for(int v=0;v<SIZE;v++){
			if(!member(v+1)){
				Cost[v] = min(Cost[v],Cost[w],Adj[w][v], v, w);
			}
		}
		printf("%d\t\t%d\t%s\n",i,w+1,d_p_string());
		s.insert(w+1);
	}
	
}

int main(){
	print_initial_adj();
   Dijksta();
	
	return 0;
}

