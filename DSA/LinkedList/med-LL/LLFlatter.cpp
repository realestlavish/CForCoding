#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->child = nullptr;
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *prev, Node *next, Node *child)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
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
/*Tc -> (2MN)
Sc-> O(N)
we can also use extra space for better solution 
*/
    static Node *Merger(Node *list1, Node *list2)
    {
        Node *dummy = new Node(-1);
        Node *res = dummy;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data < list2->data)
            {
                res->child = list1;
                res = list1;
                list1 = list1->next;
            }
            else
            {
                res->child = list2;
                res = list2;
                list2 = list2->next;
            }
            res->next = NULL;
        }
        if (list1)
        {
            res->child = list1;
        }
        else
        {
            res->child = list2;
        }

        if (dummy->child)
        {
            dummy->child->next = NULL;
            return dummy->child;
        }
    }

        static Node *OptimalFlatter(Node * head)
        {
            Node *temp = head;
            if (head == NULL || head->next == NULL)
            {
                return head;
            }
            Node *mergedhead = OptimalFlatter(head->next);
            return Merger(head, mergedhead);
        }
    };