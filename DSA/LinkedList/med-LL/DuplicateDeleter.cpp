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

    static Node *DuplicateDeleter(Node *head)
    {
        if (head->data == head->next->data)
        {
            head = head->next;
            head->prev = NULL;
        }
        Node *temphead = head;
        while (temphead != NULL && temphead->next != NULL)
        {
            Node *nextNode = temphead->next;
            if (nextNode != NULL && temphead->data == nextNode->data)
            {
                Node *daplicate=nextNode;
                nextNode = nextNode->next;
                free(daplicate);
            }
            else
            {
                temphead->next = nextNode;
                nextNode->prev = temphead;
            }
        }
        return head;
    }
};