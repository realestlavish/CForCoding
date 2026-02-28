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

    static Node *KeyDeleter(Node *head, int key)
    {
        Node *temphead = head;
        if (temphead != NULL)
        {
            if (temphead->data == key)
            {
                if (temphead = head)
                {
                    head = head->next;
                }
                Node *nextNode=temphead->next;
                Node *prevNode=temphead->prev;
                if(nextNode!=NULL) nextNode->prev=prevNode;
                if(prevNode!=NULL) prevNode->next=nextNode;
                free(temphead);
            }
            else temphead=temphead->next; 
        }
        return head;
    }
};