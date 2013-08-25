#include <stdio.h>
#include <iostream>
#include "dict.cpp"

//using namespace std;
DICT_OPEN<char> dict;
int NUM_ITEMS = 26;

void INSERT_WITH_RESULT(char i){
	if (dict.INSERT(i))
		cout<<i<<" was inserted successfully.\n";
	else
		cout<<i<<" was not inserted, it is already in the dictionary.\n";
}
void DELETE_WITH_RESULT(char i){
	if (dict.DELETE(i))
		cout<<i<<" was deleted successfully.\n";
	else
		cout<<i<<" was not deleted. It could not be found in the dictionary\n";
}

void CHECK_MEMBERSHIP(char i){
	if (dict.MEMBER(i))
		cout<<i<<" is in the dictionary.\n";
	else
		cout<<i<<" is not in the dictionary.\n";
}

int main(){
	char c = 'a';
	cout<<"Inserting "<<NUM_ITEMS<<" characters starting with a\n";
	for (int i=0;i<NUM_ITEMS;i++){
		//INSERT_WITH_RESULT(c);
		dict.INSERT(c);
		c++;
	}
	cout<<"\nAttempt to insert duplicates\n";
	INSERT_WITH_RESULT('a');
	INSERT_WITH_RESULT('a'+NUM_ITEMS-1);
	cout<<"\nState of the dictionary:\n";
	dict.PRINT();

	cout<<"\nDONE!\n";
	return 0;
}

