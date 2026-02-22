#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Sorter
{
public:
    static Node *LinkedListTraversing(vector<int> arr)
    {
        Node *head = new Node(arr[0]);
        Node *mover = head;

        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

    static Node * DutchFlagAlgo4LL(Node *head){
        if(head==NULL || head->next==NULL) return head;
        Node *temp=head;
        Node *Zerohead=new Node(-1);    
        Node *Onehead=new Node(-1);
        Node *Twohead=new Node(-1);

        Node *zero=Zerohead;    
        Node *one=Onehead;
        Node *two=Twohead;
        while (temp!=NULL)
        {
            if (temp->data==0)
            {
                zero->next=temp;
                zero=temp;
                
            }
            else if(temp->data==1){
                one->next=temp;
                one=temp;
                
            }
            else{
                two->next=temp;
                two=temp;
                
            }
            temp=temp->next;
        }
        zero->next=(Onehead->next)?Onehead->next:Twohead->next;
        one->next=Twohead->next;
        two->next=NULL;
        delete Zerohead;
        delete Onehead;
        delete Twohead;
        return Zerohead->next;
    }
};