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

class loopinll
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

    static bool BruteNodeFinder(Node *head)
    {
        unordered_map<Node *, int> mp;
        Node *temp = head;
        while (temp != NULL)
        {
            if (mp.find(temp) != mp.end())
            {
                return true;
            }
            mp[temp] = 1;
        }
        return false;
    }

    static bool HnTNodeFinder(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5};
    Node *head = loopinll ::LinkedListTraversing(vc);
    bool ans = loopinll ::BruteNodeFinder(head);
    cout << ans;
}