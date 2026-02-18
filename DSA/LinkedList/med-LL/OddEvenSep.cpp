#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        data = data;
        next = nullptr;
    }
    Node(int data, Node *next)
    {
        data = data;
        next = next;
    }
};

class OddEvenSeperator
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

    /*s1- stores odd place elements into list 
    s2- then places even place elements into list 
    s3- then assigns it into the LL
    */
    static Node *BruteSeperator(Node *head)
    {
        if (head == NULL && head->next == NULL) return head;
        Node *temp = head;
        vector<int> vs;
        while (temp != NULL && temp->next == NULL)
        {
            vs.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
            vs.push_back(temp->data);
        while (temp != NULL && temp->next == NULL)
        {
            vs.push_back(temp->data);
            temp = temp->next;
        }
        if (temp)
            vs.push_back(temp->data);

        int i = 0;
        while (temp != NULL)
        {
            temp->data = vs[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
    /* Changes pointer to next.next.next & keeps track of first even to connect it.*/
    static Node *PointerSeperator(Node *head)
    {
        if (head == NULL && head->next == NULL) return head;
        Node *oddtemp = head;
        Node *eventemp = head->next;
        Node *evenhead = head->next;
        while (eventemp != NULL && eventemp->next != NULL)
        {
            oddtemp->next = oddtemp->next->next;
            eventemp->next = eventemp->next->next;
            oddtemp=oddtemp->next;
            eventemp=eventemp->next;
        }
        oddtemp->next = evenhead;
        return head;
    }
};

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5, 10};
    Node *head = OddEvenSeperator::LinkedListTraversing(vc);
    Node *ans = OddEvenSeperator::BruteSeperator(head);
    cout << ans;
}