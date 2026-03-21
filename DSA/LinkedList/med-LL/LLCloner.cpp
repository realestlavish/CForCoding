#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node *child;
    Node *random;

    Node(int data)
    {
        this->child = nullptr;
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }

    Node(int data, Node *prev, Node *next, Node *child, Node *random)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
        this->random = nullptr;
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

    static void weaveClones(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *copyNode = new Node(temp->data);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }

    static void assignRandomPointers(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *copyNode = temp->next;
            if (temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;
            temp = copyNode->next;
        }
    }

    static Node *detachClonedList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *original = head;
        Node *copyHead = head->next;
        Node *copyTail = copyHead;

        original->next = copyHead->next;
        original = original->next;

        while (original != nullptr)
        {
            copyTail->next = original->next;
            copyTail = copyTail->next;
            original->next = copyTail->next;
            original = original->next;
        }

        return copyHead;
    }

    /* t.c = O(N), s.c = O(1) */
    static Node *Cloner(Node *head)
    {
        if (!head)
            return nullptr;

        weaveClones(head);
        assignRandomPointers(head);
        return detachClonedList(head);
    }
};