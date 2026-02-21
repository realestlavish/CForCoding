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
    /* Merges Two Sorted LinkedLists */
    static Node *Merger(Node *lefthead, Node *righthead)
    {
        Node *lefty = lefthead;
        Node *righty = righthead;
        Node *dNode = new Node(-1);
        Node *temp = dNode;
        while (lefty != NULL && righty != NULL)
        {
            if (lefty->data <= righty->data)
            {
                temp->next = lefty;
                temp = lefty;
                lefty = lefty->next;
            }
            else
            {
                temp->next = righty;
                temp = righty;
                righty = righty->next;
            }
        }
        while (lefty != NULL)
        {
            temp->next = lefty;
            temp = lefty;
            lefty = lefty->next;
        }
        while (righty != NULL)
        {
            temp->next = righty;
            temp = righty;
            righty = righty->next;
        }
        return dNode->next;
    }
    /*finds Middle Element at every step of breaking LL into Single nodes*/
    static Node *TortoisenHareAlgo(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    /*TC-> (Log N * (N+N/2)) LogN -> Merge Sort, N= Meger, N/2-> TortoisenHareAlgo (Finding Middle)
     Sc-> LogN (Recursive Stack Space)  */
    static Node *MergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *middle = TortoisenHareAlgo(head);
        Node *lefthead = head;
        Node *righthead = middle->next;
        middle->next = NULL;
        lefthead = MergeSort(lefthead);
        righthead = MergeSort(righthead);
        return Merger(lefthead, righthead);
    }
};