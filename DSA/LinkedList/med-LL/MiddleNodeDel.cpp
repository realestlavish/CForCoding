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

class MiddleNodeDeleter
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

    static Node *BruteMiddleNodeDeleter(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        Node *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        int middle = cnt / 2;
        temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            middle--;
            if (middle == 0)
            {
                break;
            }
            temp = temp->next;
        }
        Node *deltemp = temp->next;
        temp->next = deltemp->next;
        delete deltemp;
        return head;
    }

    static Node *AlgoMiddleNodeDeleter(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        Node *slow = head;
        Node *deltemp = NULL;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            deltemp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        deltemp->next = slow->next;
        delete slow;
        return head;
    }
};