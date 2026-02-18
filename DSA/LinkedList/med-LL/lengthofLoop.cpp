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
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
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

    static int bruteLenFinder(Node *head)
    {
        int ind = 1;
        unordered_map<Node *, int> mp;
        Node *temp = head;
        while (temp != NULL)
        {
            if (mp.find(temp) != mp.end())
            {
                int value = mp[temp];
                return ind - value;
            }
            mp[temp] = ind;
            ind++;
            temp = temp->next;
        }
        return 0;
    }

    /* Attaches the slow ptr to a node and then counts the rotation of LL Nodes until slow ==fast again 
    counter = number of nodes in LOOP in LL, so length of loop */
    static int LenOptimal(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        int cnt = 1;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                fast = fast->next;
                while (slow != fast)
                {
                    fast = fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5};
    Node *head = loopinll::LinkedListTraversing(vc);

    // locate nodes with values 3,4,5
    Node *node3 = nullptr, *node4 = nullptr, *node5 = nullptr;
    Node *cur = head;
    while (cur != nullptr)
    {
        if (cur->data == 3)
            node3 = cur;
        else if (cur->data == 4)
            node4 = cur;
        else if (cur->data == 5)
            node5 = cur;
        cur = cur->next;
    }

    // create the loop: 3 -> 4, 4 -> 5, 5 -> 3
    if (node3 && node4)
        node3->next = node4;
    if (node4 && node5)
        node4->next = node5;
    if (node5 && node3)
        node5->next = node3;

    int ans = loopinll::bruteLenFinder(head);
    cout << ans << "\n";
    int ans2 = loopinll::LenOptimal(head);
    cout << ans2 << "\n";
    return 0;
}