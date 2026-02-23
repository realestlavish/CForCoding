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
    /* intersection of Two LinkedLists */
    static Node *firstIntersection(Node *lefthead, Node *righthead)
    {
        Node *temp1 = lefthead;
        Node *temp2 = righthead;
        unordered_map<Node *, int> mpp;
        while (temp1 != NULL)
        {
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            if (mpp.find(temp2) == mpp.end())
            {
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }

    static Node *secondIntersection(Node *lefthead, Node *righthead)
    {
        Node *temp1 = lefthead;
        Node *temp2 = righthead;
        int cnt1 = 0;
        int cnt2 = 0;
        /*Tc-> (N1)*/
        while (temp1 != NULL)
        {
            cnt1++;
            temp1 = temp1->next;
        }
        /*Tc-> (N2)*/
        while (temp2 != NULL)
        {
            cnt2++;
            temp2 = temp2->next;
        }
        temp1 = lefthead;
        temp2 = righthead;
        int cntdiff = cnt2 > cnt1 ? cnt2 - cnt1 : cnt1 - cnt2;
        /*Tc-> (N2-N1)*/
        while (cntdiff != 0)
        {
            if (cnt2 > cnt1)
            {
                temp2 = temp2->next;
                cntdiff--;
            }
            else
            {
                temp1 = temp1->next;
                cntdiff--;
            }
        }
        /*Tc-> (N1)*/
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
                return temp1;
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        /*TOTAL Tc-> (N1)+(N2)+(N2-N1)+(N1)*/
        return NULL;
    }

    static Node *ThirdIntersection(Node *lefthead, Node *righthead)
    {
        /*TC - (N1+N2)*/
        if(lefthead==NULL || righthead==NULL) return NULL;
        Node *temp1 = lefthead;
        Node *temp2 = righthead;
        while (temp1 != temp2)
        {
            if (temp1 == NULL)temp1 = righthead;
            else temp1 = temp1->next;
            if (temp2 == NULL)temp2 = lefthead;
            else temp2 = temp2->next;   
        }
        return temp1;
    }
};