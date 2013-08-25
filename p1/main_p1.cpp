#include <stdio.h>
#include <iostream>
#include "dict.cpp"

//using namespace std;
DICT_OPEN<int> dict;
int NUM_ITEMS = 25;

void INSERT_WITH_RESULT(int i){
	if (dict.INSERT(i))
		cout<<i<<" was inserted successfully.\n";
	else
		cout<<i<<" was not inserted, it is already in the dictionary.\n";
}
void DELETE_WITH_RESULT(int i){
	if (dict.DELETE(i))
		cout<<i<<" was deleted successfully.\n";
	else
		cout<<i<<" was not deleted. It could not be found in the dictionary\n";
}

void CHECK_MEMBERSHIP(int i){
	if (dict.MEMBER(i))
		cout<<i<<" is in the dictionary.\n";
	else
		cout<<i<<" is not in the dictionary.\n";
}

int main(){
	cout<<"Inserting integers from 0 to "<<NUM_ITEMS-1<<"\n";
	for (int i=0;i<NUM_ITEMS;i++){
		INSERT_WITH_RESULT(i);
	}
	cout<<"\nAttempt to insert duplicates\n";
	INSERT_WITH_RESULT(0);
	INSERT_WITH_RESULT(NUM_ITEMS-1);
	cout<<"\nState of the dictionary:\n";
	dict.PRINT();
	cout<<"\nMake sure all of our inserted items are members\n";
	for (int i=0;i<NUM_ITEMS;i++){
		CHECK_MEMBERSHIP(i);
	}
	cout<<"\nMake sure non-inserted items are NOT members\n";
	CHECK_MEMBERSHIP(-1);
	CHECK_MEMBERSHIP(NUM_ITEMS+1);
	cout<<"\nDelete all of the inserted items\n";
	for (int i=0;i<NUM_ITEMS;i++){
		DELETE_WITH_RESULT(i);
	}
	cout<<"\nDelete items again, nothing could happen\n";
	DELETE_WITH_RESULT(0);
	DELETE_WITH_RESULT(NUM_ITEMS-1);
	cout<<"\nDelete some items that were never inserted, nothing could happen\n";
	DELETE_WITH_RESULT(-1);
	DELETE_WITH_RESULT(NUM_ITEMS+1);
	cout<<"\nState of the dictionary:\n";
	dict.PRINT();
	cout<<"\nInsert all of our items again\n";
	for (int i=0;i<NUM_ITEMS;i++){
		INSERT_WITH_RESULT(i);
	}
	cout<<"\nState of the dictionary:\n";
	dict.PRINT();
	cout<<"\nTest MAKENULL\n";
	dict.MAKENULL();
	cout<<"\nState of the dictionary:\n";
	dict.PRINT();

	cout<<"\nDONE!\n";
	return 0;
}

