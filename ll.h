#include "Dona.h"

class LL {
  donaPtr hol; // head of linked list
  donaPtr eol; // end of linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(string, int);
  void printList();
  ~LL();
/* With doubly linked list*/

 void printListR();

};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  //cout << "deleting all donas" << endl;
  donaPtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    t = hol->get_next();
    delete hol;
    hol = t;
  }
}

// insert a new value into the list in sorted order
void LL::insert(string name, int value) {
  donaPtr newPtr;      // pointer to new dona
  donaPtr previousPtr; // pointer to previous dona in list
  donaPtr currentPtr;  // pointer to current dona in list

  newPtr = new dona(name, value); // create dona & put value in

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && value > currentPtr->get_value()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next dona
                                          
    } // end while

    // insert new dona at beginning of list
    if (previousPtr == NULL) {
        newPtr->set_next(hol);
        hol = newPtr;
       
      }  // end if
    else { 
      // insert new dona between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      
      newPtr->set_next(currentPtr);
        } // end else
    ++size;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

// delete a list element
int LL::deletes(int value) {
  donaPtr previousPtr; // pointer to previous dona in list
  donaPtr currentPtr;  // pointer to current dona in list
  donaPtr tempPtr;     // temporary dona pointer

  // delete first dona
  if (value == hol->get_value()) {
    tempPtr = hol;  // hold onto dona being removed
    hol = hol->get_next(); // de-thread the donas
 
    size--;

    delete tempPtr; // free the de-threaded dona

    return value;
  } // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->get_value() != value) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next dona
      if (currentPtr == hol)
        currentPtr = NULL;
    } // end while

    // delete dona  currentPtr
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      currentPtr = currentPtr->get_next();
      previousPtr->set_next(currentPtr);
     
    
      delete tempPtr;
      size--;
      return value;
    } // end if
  }   // end else

  return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; } // end function isEmpty

//printListR()

// print the list
void LL::printList() {
  donaPtr currentPtr = hol;
  // if list is empty
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The list is:" << endl;

    // while not the end of the list
    // while ( currentPtr != NULL ) {
      int i;
      for (i = 0; i < size; i++) {
      cout << i+1<< ". ";
      currentPtr->print();
       cout <<endl;
       currentPtr = currentPtr->get_next();
    } // end while

    //puts(" NULL\n");

  } // end else
}

   void LL::printListR() {
   donaPtr currentPtr = hol;
   // if list is empty
   if (size == 0) {
     //cout << "List is empty." << endl;
   } // end if
   else {
     //cout << "The reversed list is:" << endl;

     // while not the end of the list
     // while ( currentPtr != NULL ) {
     int i;

     // set currentPtr to the last dona
     for (i = 0; i < size-1; i++) {
       currentPtr = currentPtr->get_next();
     } // end while

    int topNum;

     if(size<3) //Prevent coredump if size < 3
      topNum = size;
     else
      topNum = 3; //End coredump preventation


     for (i = 0; i < topNum; i++) {
       cout<< i+1<< ".";
       currentPtr->print();
       cout<< endl;
       currentPtr = currentPtr->get_prev();
      } // end while


     //puts(" NULL\n");

   } // end else

 } // end function printListR