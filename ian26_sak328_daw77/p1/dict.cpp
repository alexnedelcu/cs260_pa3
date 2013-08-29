#include <stdio.h>
#include <iostream>

using namespace std;
#define NUM_BUCKETS 5

struct probe_result{
	int probe_count;
	bool result;
	probe_result(){
		probe_count=0;
		result=false;
	}
};

template<typename X>
struct pNode{
	X data;
	pNode<X> *next;
	pNode(){
		next=NULL;
	}
};

//To implement a DICT_OPEN<TYPE> the function DICT_OPEN.hash(TYPE t) must be
//implemeted. Currently, only int is implemented.
template<typename X>
class DICT_OPEN{
	private:
		pNode<X> *heads[NUM_BUCKETS];
		int hash(int x){
			if (x<0)
				x=-x;
			return x%NUM_BUCKETS;
		}
		int hash(char c){
			return c%NUM_BUCKETS;
		}	
	public:
		DICT_OPEN(){
			for (int i=0;i<NUM_BUCKETS;i++){
				heads[i] = NULL;
			}
		}
		probe_result INSERT(X item){
			probe_result p;
			p = MEMBER(item);
			if (!p.result){//Member probe was false
				int bucket = hash(item);
				pNode<X> *old_head = heads[bucket];
				heads[bucket] = new pNode<X>();
				heads[bucket]->data = item;
				heads[bucket]->next = old_head;
				p.result = true;
			}else{
				p.result = false;
			}
			return p;
		}

		probe_result DELETE(X item){
			probe_result p;
			int bucket = hash(item);
			p.probe_count = 1;
			if (heads[bucket]!=NULL){
				if(heads[bucket]->data == item){
					//Item is the first in the list
					heads[bucket] = heads[bucket]->next;
					p.result = true;
					return p;
				}
				//Otherwise, continue to search
				pNode<X> *previous = heads[bucket];
				while (previous->next!=NULL){
					//The next item is what we are looking for
					p.probe_count++;
					if (previous->next->data == item){
						//Remove item
						previous->next = previous->next->next;
						p.result = true;
						return p;
					}
					//Check the next item
					previous = previous->next;
				}
			}
			return p;
		}
		probe_result MEMBER(X item){
			probe_result p;
			int bucket = hash(item);
			pNode<X> *node = heads[bucket];
			p.probe_count = 1;//Initial probe
			while (node!=NULL){
				if(node->data==item){
					p.result = true;
					return p;
				}
				node=node->next;
				p.probe_count++;
			}
			return p;
		}
		void MAKENULL(){
			for (int i=0;i<NUM_BUCKETS;i++){
				heads[i] = NULL;
			}
		}
		void PRINT(){
			for (int i=0;i<NUM_BUCKETS;i++){
				cout<<"["<<i<<"] ->\t";
				pNode<X> *node = heads[i];
				while (node!=NULL){
					cout<<node->data<<"\t";
					node = node->next;
				}
				cout<<endl;
			}

		}
};
