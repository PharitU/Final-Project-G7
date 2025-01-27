#ifndef queue_h
#define queue_h
#include "Node.h"
#include "Charity.h"
class Queue {
	charityPtr headPtr,tailPtr;
	int size;
  string charity_name;
  int amount = 0;
  int value;
  int remaining;
public:
    void enqueue(string, int);
    int dequeue();
    void printcharlist();
    bool emptylist();
    int subtract(int);
    int next_charity();
    int get_amount();
    void set_remainder(int);
    string get_firstname();
    Queue();
    ~Queue();
};


void Queue::enqueue(string charity_name, int amount){
  charityPtr new_charity= new charity(charity_name, amount);
if(new_charity)
{ 
    /* Add head and tail for me please 
   1. connect & Change tail
  2. (may be) change head  when the queue is empty
  3. increase size*/
  if(size == 0)
  {
    headPtr = new_charity;
    tailPtr = new_charity;
  } 
  else
  {
    tailPtr->set_next(new_charity);
    tailPtr = new_charity;
  }
  size++; //tommy changed from size++
	
 }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
     charityPtr t=headPtr;
     int amount= t->get_amount();
     headPtr = t->get_next();
     if(size == 1)
     {
      tailPtr = NULL;
     }
     size--;
    //  if(size == 1){
    //   headPtr = NULL;
    //   tailPtr = NULL;
    //  }
    //  if(size > 0)
    //  {
    //   amount = t->get_next()->get_amount();
    //  }
    //  else amount = t->get_amount();

     if (headPtr != NULL)
     {
      cout << "Next Charity Target " << headPtr -> get_amount()<<endl;
     }
     else
     {
      cout << "All charities completed " << endl;
     }
     //cout<<"Dequeing "<<t->get_amount()<<endl;

     delete t;
     return amount;
  }
  cout<<"Empty queue";
  return -1;
}

string Queue::get_firstname(){
  return headPtr->get_name();
}

bool Queue::emptylist(){
  return headPtr == NULL;
}

void Queue::printcharlist(){
  if (size == 0)
  {
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"Charity list is currently empty"<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
  } // end if
  else
  {
    cout<<endl;
    cout<< "Charity list is:" << endl;
    int k;
    charityPtr j = headPtr;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    for(k=0; k<size; k++)
    {
      cout<<j->get_name()<<" With the Goal Of "<<j->get_amount()<<" Baht"<<endl;
      j = j->get_next();
    } //end for
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    //   for (i = 0; i < size; i++) {
    //   cout << i+1<< ". ";
    //   currentPtr->print();
    //    cout <<endl;
    //    currentPtr = currentPtr->get_next();
    // } // end for 
  } // end else
}

// int Queue::subtract(int amount, int value){
//   remaining = amount - value;
//   return remaining;
// }

int Queue::subtract(int value){
  charityPtr x = headPtr;
  remaining = x->get_amount() - value;
  x->set_amount(remaining);
  return remaining;
}

int Queue::next_charity(){
  int amount;
  charityPtr t=headPtr;
  if (size > 0)
  {
    amount = t->get_next()->get_amount();
  }
  return amount;
}

int Queue::get_amount(){
  return amount;
}

Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    
}
Queue::~Queue(){

  //delete all remaining Queue (i.e. DQ all) 

  //cout<<"Start clearing queue..."<<endl;

  while(size>0)
  {
    dequeue();
  }
    
}


#endif