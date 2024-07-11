#include <iostream>
using namespace std;
#include "Charity.h"
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
    int value = 0; // Money from Donators
    int amount = 0; // Money required for Charity
    int remaining = 0; // Money remaining from amount - value
    int leftovers = 0; // Money leftover that went over the charity
    int random = 0; //variable for leftover :D

    while(choice != 5)
    {
        cout<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"=-=-=-= Choose 1-5 =-=-=-=-=-"<< endl;
        cout<< "1.Enter Donator"<< endl;
        cout<< "2.Display Top 3 Donator"<< endl;
        cout<< "3.Enter Charity"<< endl;
        cout<< "4.Display All Charity List"<< endl;
        cout<< "5.Stop"<< endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
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
                    if (value != 0 && amount != 0) //Check if there's money from donors and amount needed for charity
                    {
                        if(remaining == 0) //First-time :D
                        {
                            remaining = q.subtract(value);
                            if(remaining == 0 || remaining < 0) //Remaining = remaining of amount 
                            {
                                q.dequeue();
                                if(remaining < 0) //ถ้า remaining go below zero use it as funds for next charity (leftovers)
                                {
                                    leftovers = remaining * -1;
                                    random = q.subtract(leftovers);
                                    if(q.get_amount() == 0)
                                    {
                                        q.dequeue();
                                    }
                                }
                                //amount = q.next_charity();
                            } 
                            else //remaining != 0 will tell how much more need
                            {
                                cout<<"Charity "<<q.get_firstname()<<" now needs "<<remaining<<" more Baht"<<endl;
                                amount = remaining;
                                //q.set_remainder(remaining);
                            }
                        }
                        else //I got lost half way and if doesn't work anymore
                        {
                            remaining = q.subtract(value);
                             if(remaining <= 0) //tom change from rem == 0 // 
                            {
                                q.dequeue();
                                amount = q.get_amount();
                                cout<<q.get_amount()<<endl;
                                if(remaining < 0) //ถ้า remaining go below zero use it as funds for next charity (leftovers)
                                {
                                    leftovers = remaining * -1;
                                    random = q.subtract(leftovers);
                                }
                                //cout<<amount<<endl;
                                
                            }
                            else
                            {
                                cout<<"Charity "<<q.get_firstname()<<" now needs "<<remaining<<" more Baht"<<endl;
                                amount = remaining;
                            }
                        } // end if // all this don't work don't know why just gonna comment it, it wont affect much 
                        // if (remaining <= 0){
                        //         remaining = q.subtract(amount, value);
                        //         q.dequeue();
                        //         amount = q.next_charity();
                        //         // remaining = 0;
                        //         cout<<amount<<" "<<value<<" "<<remaining<<endl;
                        //         //~queue();
                        // } // end if
                        // else{
                        //     cout<<"Charity "<<charity_name<<" now needs "<<remaining<<" more Yuan"<<endl;
                        // } // end else
                    }
                break;  // case 1 like 80 lines ยาวเกินครับพี่ชาย    
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