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

    static Node *TortoisenHareAlgo(Node *head)
    {
        if (head == NULL)
            return 0;

        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    static Node *RecursiveReverser(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *newHead = RecursiveReverser(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    static bool bruteLenFinder(Node *head)
    {
        Node *temp = head;
        stack<int> st;
        while (temp != NULL)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (!st.empty())
        {
            if (st.top() != temp->data)
                return false;
            else
            {
                st.pop();
                temp = temp->next;
            }
        }
        return true;
    }

    static bool LenOptimal(Node *head)
    {
        Node *temp = head;
        Node *middle = TortoisenHareAlgo(head);
        Node *lasthead = RecursiveReverser(middle->next);
        Node *last = lasthead;
        while (last != NULL)
        {
            if (temp->data != last->data)
            {
                RecursiveReverser(lasthead);
                return false;
            }
            else
            {
                temp = temp->next;
                last = last->next;
            }
        }
        RecursiveReverser(lasthead);
        return true;
    }
};

int main()
{
    vector<int> vc = {3, 7, 5, 7, 3};
    Node *head = loopinll::LinkedListTraversing(vc);

    bool ans = loopinll::bruteLenFinder(head);
    cout << ans << "\n";
    int ans2 = loopinll::LenOptimal(head);
    cout << ans2 << "\n";
    return 0;
}