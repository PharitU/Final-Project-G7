#include <iostream>
using namespace std;
#include "Queue.h"
#include "ll.h"
#include "string.h"

int main(void) {

    int choice;
    LL donaList;

    string name;
    int value;

    while(choice != 3)
    {
        cout<< "Choose 1-3"<< endl;
        cout<< "1.Enter Donator"<< endl;
        cout<< "2.Enter Charity"<< endl;
        cout<< "3.Stop"<< endl;
        cin>> choice;

        switch (choice)
        {
            case 1:
                cin>> name>> value; 
                donaList.insert(name, value);
                donaList.printList();
                break;

        }
    }


//   Queue q;
//    int i,x;
   

//  for(i=1;i<argc;i++){
//         if(strcmp(argv[i],"x")==0){
//             x=q.dequeue();
//             //if(x!=-1) cout<<"dequeing "<<x<<endl;
//         }
//         else {
//        q.enqueue(atoi(argv[i]));
           
//         }
//  }
  return 0;
}