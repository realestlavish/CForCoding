#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = NULL;
        this->next = nullptr;
    }
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
    /*T.C -> TLE*/
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
    /*T.C -> (3N)*/
    static Node *TwoBruteAdder(Node *firsthead, Node *secondhead)
    {
        Node *dnode = new Node();
        Node *temp3head = dnode;
        if (firsthead == NULL) return secondhead;
        if (secondhead == NULL) return firsthead;
        int carry = 0;
        Node *temp1 = firsthead;
        Node *temp2 = secondhead;
        while (temp1 != NULL || temp2 != NULL || carry != 0){
            int val1 = (temp1 != NULL) ? temp1->data : 0;
            int val2 = (temp2 != NULL) ? temp2->data : 0;
            int sum = (val1 + val2 + carry);
            carry=sum/10;
            Node *sumNodes= new Node(sum%10);
            temp3head->next = sumNodes;
            temp3head=temp3head->next;
            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
        }
        return dnode->next;
    }
};
