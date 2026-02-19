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

    static Node *SelfBruteRemover(Node *head, int i)
    {
        if (head == NULL)
            return NULL;
        int len = LengthofLL(head);
        if (i > len)
            return NULL;
        // remove head
        if (i == len)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node *temp = head;
        Node *backtemp = NULL;
        int cnt = 1;
        while (temp != NULL)
        {
            if (cnt == (len - i + 1))
            {
                backtemp->next = temp->next;
                temp->next = NULL;
                delete temp;
                break;
            }
            backtemp = temp;
            cnt++;
            temp = temp->next;
        }
        return head;
    }

    static Node *StriverBruteRemover(Node *head, int i)
    {
        if (head == NULL)
            return NULL;
        int len = LengthofLL(head);
        if (i > len)
            return NULL;
        // remove head
        if (i == len)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node *temp = head;
        Node *deltemp = NULL;
        int res = len - i;
        while (temp != NULL)
        {
            res--;
            if (res == 0)
            {
                break;
            }
            temp = temp->next;
        }
        deltemp = temp->next;
        temp->next = temp->next->next;
        delete deltemp;
        return head;
    }

    static Node *PointerRemover(Node *head, int im)
    {
        if (head == NULL)
            return NULL;
        int len = LengthofLL(head);
        if (im > len) return NULL;
        // remove head
        if (im == len)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node *deltemp = NULL;
        Node *fast = head;
        Node *slow = head;
        for (int i = 0; i < im; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {

            fast = fast->next;
            slow = slow->next;
        }
        deltemp = slow->next;
        slow->next = slow->next->next;
        delete deltemp;
        return head;
    }
};

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5, 10};
    int k = 2;
    Node *head = OddEvenSeperator::LinkedListTraversing(vc);
    Node *ans = OddEvenSeperator::SelfBruteRemover(head, k);
    cout << ans;
}