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

class middleELofLL
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

    static int LengthofLL(Node *head)
    {
        Node *temp = head;
        int cnt = 0;

        while (temp != nullptr)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    static int BrutemiddleEL(Node *head)
    {
        if (head == NULL)
            return -1;

        Node *temp = head;
        int len = LengthofLL(head);
        int half = (len / 2) + 1;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            if (cnt == half)
                return temp->data;
            else
                temp = temp->next;
        }
        return -1;
    }

    static int TortoisenHareAlgo(Node *head)
    {
        if (head == NULL)
            return -1;

        Node *slow= head;
        Node *fast=head;
        while (fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};

int main()
{
    vector<int> vc = {1, 2, 3, 4,5, 10};
    Node *head = middleELofLL::LinkedListTraversing(vc);
    int ans = middleELofLL::BrutemiddleEL(head);
    int ans1=middleELofLL::TortoisenHareAlgo(head);
    cout << ans<<endl;
    cout<<ans1;
}