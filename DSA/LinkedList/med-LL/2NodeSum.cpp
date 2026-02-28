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

    static vector<pair<int, int>> bruteSumNodes(Node *head, int keysum)
    {
        Node *temp1 = head;
        vector<pair<int, int>> vs;
        while (temp1 != NULL)
        {
            Node *temp2 = temp1->next;
            int val1 = temp1->data;
            int val2 = temp2->data;
            while (temp2 != NULL && (val1 + val2) < keysum)
            {
                if ((val1 + val2) == keysum)
                {
                    vs.push_back({val1, val2});
                    temp2 = temp2->next;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return vs;
    }

    static vector<pair<int, int>> optiimalSumNodes(Node *head, int keysum)
    {
        vector<pair<int, int>> vs;
        if(head==NULL) return vs;
        Node *left = head;
        Node *right=NULL;
        while (left != NULL)
        {
            right = left;
            left=left->next;
        }
        left = head;
        while (left->data< right->data)
        {
            int val1=left->data;
            int val2=right->data;
            int sum=val1+val2;
            if(sum<keysum) left=left->next;
            else if(sum==keysum) {
                vs.push_back({val1, val2});
                right=right->prev;
                left=left->next;
            }
            else right=right->prev;
        }
        return vs;
    }
};