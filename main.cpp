#include <iostream>
using namespace std;
#include "Queue.h"
#include "ll.h"
#include "string.h"

void end(){
    int y;
    for(y=0;y<13;y++)
    {
        cout<<endl;
    }
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"Thank you for using our charity service <3"<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    for(y=0;y<7;y++)
    {
        cout<<endl;
    }
}

int main(void) {

    int choice;
    LL donaList;
    Queue q;

    string name;
    string charity_name;
    int value = 0;
    int amount = 0;
    int remaining = 0;
    int remainings = 0;

    while(choice != 5)
    {
        cout<< endl<< "Choose 1-5"<< endl;
        cout<< "1.Enter Donator"<< endl;
        cout<< "2.Display Top 3 Donator"<< endl;
        cout<< "3.Enter Charity"<< endl;
        cout<< "4.Display All Charity List"<< endl;
        cout<< "5.Stop"<< endl;
        cin>> choice;

        if (cin.fail()) //False input
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        switch (choice)
        {
            case 1:
                if(q.emptylist())
                {
                    cout<<endl;
                    cout<<"=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    cout<<"There's no charity available right now!"<<endl;
                    cout<<"=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    break;
                } // end big if
                else
                { 
                    cout<< endl <<"Enter name and amount of money"<< endl;
                    cin>> name>> value;
                    cout<<endl;
                    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    cout<<name<<" has donated "<<value<<" to our donation service!"<<endl;
                    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    if (cin.fail()) //False input
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                    } // end if
                    donaList.insert(name, value);
                    if (value != 0 && amount != 0) 
                    {
                        if(remaining == 0)
                        {
                            remaining = q.subtract(amount, value);
                        }
                        else
                        {
                            amount = remaining;
                            remaining = q.subtract(amount, value);
                        } // end if
                        if (remaining <= 0){
                                amount = q.dequeue();
                                remaining = 0;
                                cout<<amount<<" "<<value<<" "<<remaining<<endl;
                                //~queue();
                        } // end if
                        else{
                            cout<<"Charity "<<charity_name<<" now needs "<<remaining<<" more Yuan"<<endl;
                        } // end else
                    }
                break;        
                } // end big else
            case 2:
                if (donaList.isEmpty())
                    cout<< endl<< "No donator yet"<< endl;
                else
                    cout<< endl<< "Top 3 Donators are"<< endl;
                    donaList.printListR();              
                break;
            case 3:
                cout<<"Enter charity name and amount"<<endl;
                cin>> charity_name>> amount;
                q.enqueue(charity_name, amount);
                break;
            case 4:
                if (q.emptylist())
                    cout<<"The charity list is empty"<<endl;
                else
                    q.printcharlist();
                break;
            case 5:
                end();
                break;
            default:
                cout<<"Please pick an option between 1 - 5"<<endl;
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