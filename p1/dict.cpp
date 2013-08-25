#include <stdio.h>
#include <iostream>

using namespace std;
#define NUM_BUCKETS 5

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
			return x%NUM_BUCKETS;
		}
		int hash(char c){
			cout<<"Hash of char not implemented... returning 0...\n";
			return 0;
		}	
	public:
		DICT_OPEN(){
			for (int i=0;i<NUM_BUCKETS;i++){
				heads[i] = NULL;
			}
		}
		bool INSERT(X item){
			if (!MEMBER(item)){
				int bucket = hash(item);
				pNode<X> *old_head = heads[bucket];
				heads[bucket] = new pNode<X>();
				heads[bucket]->data = item;
				heads[bucket]->next = old_head;
				return true;
			}
			//x is already a member, return false
			return false;
		}

		bool DELETE(X item){
			int bucket = hash(item);
			if (heads[bucket]!=NULL){
				if(heads[bucket]->data == item){
					//Item is the first in the list
					heads[bucket] = heads[bucket]->next;
					return true;
				}
				//Otherwise, continue to search
				pNode<X> *previous = heads[bucket];
				while (previous->next!=NULL){
					//The next item is what we are looking for
					if (previous->next->data == item){
						//Remove item
						previous->next = previous->next->next;
						return true;
					}
					//Check the next item
					previous = previous->next;
				}


			}
			return false;
		}
		bool MEMBER(X item){
			int bucket = hash(item);
			pNode<X> *node = heads[bucket];
			while (node!=NULL){
				if(node->data==item)
					return true;
				node=node->next;
			}
			return false;
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
/*

   ~pList(){
      MAKENULL();
   }

   pNode<X>* FIRST(){
      return _head;

   }


   X RETRIEVE(pNode<X> *p){
      return p->data;
   }

   pNode<X>* LOCATE(X item){
       pNode<X> *q = _head;
       while(q->next!=NULL){
         if(q->next->data==item){
            return q;
         }
         q=q->next;
      }
      cout<<"Could not LOCATE value:"<<item<<"... returning NULL...\n";
      return  (pNode<X>*) NULL;
   }

   pNode<X>* END(){
      pNode<X> *q = _head;
      while(q->next!=NULL){
         q=q->next;
      }
      return q;
   }

   pNode<X>* NEXT(pNode<X> *p){
      return p->next;
   }

   pNode<X>* PREVIOUS(pNode<X> *p){
       pNode<X> *q = _head;
       while(q->next!=NULL){
         if(q->next==p){
            return q;
         }
         q=q->next;
       }
       cout<<"PREVIOUS called with invalid pointer... returning NULL...\n";
       return  (pNode<X>*) NULL;
   }


   void INSERT(X item, pNode<X> *position){
      pNode<X> *tmp = position->next;
      pNode<X> *new_node = new pNode<X>();
      position->next=new_node;
      new_node->data=item;
      new_node->next=tmp;
   }

   void DELETE(pNode<X>* p){
      p->next = p->next->next;
   }

   void MAKENULL(){
      if(_head->next!=NULL){
         pNode<X>* iter = _head->next;
         pNode<X>* next;
         do{
            next = iter->next;
            delete iter;
            iter = next;
         }while (next!=NULL);
      }
      _head->next=NULL;
   }
*/
