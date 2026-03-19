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

    static Node *kthelement(Node *head, int k)
    {
        Node *temp = head;
        while (temp && k > 0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    static Node *RecursiveReverser(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *newHead = RecursiveReverser(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    static Node *KSizeReverser(Node *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp = head;
        Node *nextNode = NULL;
        Node *prevNode = NULL;
        while (temp != NULL)
        {
            Node *kelement = kthelement(temp, k);
            if (kelement == NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            nextNode = kelement->next;
            kelement->next = NULL;
            RecursiveReverser(temp);
            if (temp == head)
                head = kelement;
            else
            {
                prevNode->next = kelement;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};