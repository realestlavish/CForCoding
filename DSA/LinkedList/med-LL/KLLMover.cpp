#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *prev, Node *next)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
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

    static Node *BruteKSizeMover(Node *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp = head;
        Node *B4head = head;
        while (k > 0)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *last=temp;
            Node* prevnode=last->prev;
    
            prevnode->next=NULL;
            last->next=B4head;
            B4head->prev=last;
            prevnode=NULL;
            head=last;
            k--;
        }
        return head;
    }

    static int lenfinder(Node *head){
        Node *temp=head;
        int cnt=0;
        while (temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
     static Node *OptimalKSizeMover(Node *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp = head;
        int len=lenfinder(head);
        if(k%len==0) return head;
        if(k>len){
            k=(k%len);
        }
        Node *tail=head;
        while (tail->next!=NULL)
        {
            tail=tail->next;
        }
        int remover=len-k-1;
        while (temp!=NULL&&remover>0)
        {
            temp=temp->next;
            remover--;
        }
        Node *nHead=temp->next;
        temp->next=NULL;
        nHead->prev=NULL;
        tail->next=head;
        head->prev=tail;
        head=nHead;
        return head;
    }
};