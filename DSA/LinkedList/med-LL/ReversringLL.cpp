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

class reverseem
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

    static Node *ReverserBrute(Node *head)
    {
        Node *temp = head;
        stack<int> st;
        while (temp != NULL)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

    static Node *ReverserOpt(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    /*breaks into smaller nd smaller nodes, and then reverses them*/
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
};

int main()
{
    vector<int> vc = {1, 2, 3, 4, 5, 10};
    Node *head = reverseem::LinkedListTraversing(vc);
    Node *ans = reverseem::RecursiveReverser(head);
    cout << ans;
}