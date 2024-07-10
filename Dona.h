#ifndef dona_h
#define dona_h
#include <iomanip>
#include "string.h"
using namespace std;

class dona{
    int value;
    string name;
    dona* nextPtr;
    dona* prevPtr;
public:
    dona(string, int);
    ~dona();
    void set_next(dona*);
    dona* get_next();
    dona* get_prev();
    int get_value();
    string get_name();
    void print();
};
typedef dona* donaPtr;


dona::dona(string n, int x){
    name = n;
    value = x;
    nextPtr = NULL;
    //pPtr =NULL; not using doubly
}

donaPtr dona::get_next(){
    return nextPtr;

}

donaPtr dona::get_prev(){
    return prevPtr;

}

string dona::get_name()
{
    return name;
}

int dona::get_value(){
    return value;

}


void dona::set_next(donaPtr t){
     nextPtr=t;
     if(t) t->prevPtr = this;

}

void dona::print()
{
    cout << setw(3) << name << " " << value;
}

dona::~dona(){
     //cout<<"deleting "<<value<<endl;

}






#endif