#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data)
    {
        data = data;
        next = nullptr;
        back = nullptr;
    }
    Node(int data, Node *next, Node *back)
    {
        data = data;
        next = next;
        back = back;
    }
};

class loopstarters
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

public:
    static int loopstarter(Node *head)
    {
        unordered_map<Node *, int> mp;
        Node *temp = head;
        while (temp != NULL)
        {
            if (mp.find(temp) != mp.end())
            {
                return temp->data;
            }
            mp[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }

    static int hairntrtoiseloop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow->next->data;
            }
        }
        return NULL;
    }
};

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5};
}