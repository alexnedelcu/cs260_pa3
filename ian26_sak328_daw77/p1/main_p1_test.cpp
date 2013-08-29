#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "dict.cpp"

//using namespace std;
DICT_OPEN<int> dict;
#define NUM_ITEMS 50000
#define ITEM_MAX  100000
#define NUM_TRIALS 10000

int success_insert_probes=0;
int fail_insert_probes=0;
int success_delete_probes=0;
int fail_delete_probes=0;

void INSERT_NEW_ITEM(){
		int i = rand()%ITEM_MAX;
		probe_result p = dict.INSERT(i);
		while(!p.result){	//Keep inserting until the item is new
			i = rand()%ITEM_MAX;
			p = dict.INSERT(i);
		}
}

void INSERT_NEW_ITEM_TIMED(){
		int i = rand()%ITEM_MAX;
		probe_result p = dict.INSERT(i);
		while(!p.result){	//Keep inserting until the item is new
			i = rand()%ITEM_MAX;
			p = dict.INSERT(i);
		}
		dict.DELETE(i); //remove the item
		success_insert_probes+=p.probe_count;
}

void INSERT_EXISTING_ITEM_TIMED(){
		int i = rand()%ITEM_MAX;
		probe_result p = dict.INSERT(i);
		while(p.result){	//Keep inserting until the item is already present
			dict.DELETE(i);
			i = rand()%ITEM_MAX;
			p = dict.INSERT(i);
		}
		fail_insert_probes+=p.probe_count;
}

void DELETE_ITEM_TIMED(){
		int i = rand()%ITEM_MAX;
		probe_result p = dict.DELETE(i);
		while(!p.result){	//Keep inserting until the item is deleted
			i = rand()%ITEM_MAX;
			p = dict.DELETE(i);
		}
		dict.INSERT(i); //put the item back
		success_delete_probes+=p.probe_count;
}
void FAILED_DELETE_ITEM_TIMED(){
		int i = rand()%ITEM_MAX;
		probe_result p = dict.DELETE(i);
		while(p.result){	//Keep deleting until there is a failed delete
			dict.INSERT(i); //put the item back
			i = rand()%ITEM_MAX;
			p = dict.DELETE(i);
		}
		fail_delete_probes+=p.probe_count;
}

int main(){
	/* initialize random seed: */
	srand (time(NULL));


	cout<<"Inserting "<<NUM_ITEMS<<" random integers into a hash table with 5 buckets\n";
	for (int i=0;i<NUM_ITEMS;i++){
		INSERT_NEW_ITEM();
	}
	
	cout<<"Performing "<<NUM_TRIALS<<" random inserts and tallying # of probes.\n";
	for (int i=0;i<NUM_TRIALS;i++){
		INSERT_NEW_ITEM_TIMED();
	}
	cout<<"Performing "<<NUM_TRIALS<<" random inserts of existing items and tallying # of probes.\n";
	for (int i=0;i<NUM_TRIALS;i++){
		INSERT_EXISTING_ITEM_TIMED();
	}
	cout<<"Performing "<<NUM_TRIALS<<" random deletes and tallying # of probes.\n";
	for (int i=0;i<NUM_TRIALS;i++){
		DELETE_ITEM_TIMED();
	}
	cout<<"Performing "<<NUM_TRIALS<<" random deletes of items NOT in the dictionary and tallying # of probes.\n";
	for (int i=0;i<NUM_TRIALS;i++){
		FAILED_DELETE_ITEM_TIMED();
	}

	cout<<"_____________TEST CONDITIONS____________\n";
	cout<<"N: "<<NUM_ITEMS<<endl;
	cout<<"B: 5\n";
	cout<<"_________________RESULTS________________\n";
	cout<<"Average Insert of New Item :\t\t"<<(double)success_insert_probes/NUM_TRIALS<<endl;
	cout<<"Average Insert of Existing Item:\t"<<(double)fail_insert_probes/NUM_TRIALS<<endl;
	cout<<"Average Successful Delete :\t\t"<<(double)success_delete_probes/NUM_TRIALS<<endl;
	cout<<"Average Unsuccessful Delete :\t\t"<<(double)fail_delete_probes/NUM_TRIALS<<endl;
	//probe_result p = dict.INSERT(i);
	//probe_result p = dict.DELETE(i);
	//probe_result p = dict.MEMBER(i);
	return 0;
}

