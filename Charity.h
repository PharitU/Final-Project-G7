#ifndef charity_h
#define charity_h
#include <iomanip>
#include "string.h"
using namespace std;

class charity{
    int amount;
    int remaining;
    string charity_name;
    charity* nextPtr;
public:
    charity(string, int);
    ~charity();
    void set_next(charity*);
    charity* get_next();
    int get_value();
    string get_name();
    void print();
    int get_remainder();
    void set_value(int);
};
typedef charity* charityPtr;


charity::charity(string n, int x){
    charity_name = n;
    amount = x;
    nextPtr = NULL;
    cout<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"Created Charity "<< charity_name<< " With the goal of "<< amount <<" Yuan" << endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    //pPtr =NULL; not using doubly
}

charityPtr charity::get_next(){
    return nextPtr;
}

string charity::get_name()
{
    return charity_name;
}


void charity::set_value(int n){
     amount=n;
}

int charity::get_value(){
    return amount;
}

int charity::get_remainder(){
  return remaining;
}

void charity::set_next(charityPtr t){
     nextPtr=t;

}

void charity::print()
{
    cout << setw(3) << charity_name << " " << amount;
}

charity::~charity(){
     cout<<"Charity "<<charity_name<<" Completed <3"<<endl;

}






#endif