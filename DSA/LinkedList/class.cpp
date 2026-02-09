#include <bits/stdc++.h>
using namespace std;

/* CLASS is more beneficial to use than STRUCT, as it helps more in OOP, when you take self defined objects. 
CONSTRUCTOR is used to initialise objects;
in this class, the NODE is a self defined data type,in first constructor it takes input of 2 values : an integer and a null ptr */
class node
{
    public:
        int data;
        node *next;
    // first constructor
    public:
    node(int data1, node* next1){
        data=data1;
        next=next1;
    }
    //second constructor, in this the next is preset to null ptr so no need to input nullptr every time.
    public:
    node(int data1){
        data=data1;
        next=nullptr;
    }
};

int main(){
    vector<int> arr ={2,3,4,45,5};
    node*y=new node(arr[0]);
    cout << y; // gives address of ptr;
    cout<< y ->data; //gives the input value;
    cout << y.data /*or*/ << y.next; //just like map, but we have to remove NEW from the node statement.
}