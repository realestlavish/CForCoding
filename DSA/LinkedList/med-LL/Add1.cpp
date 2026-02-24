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

    static Node *OneBruteAdder(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *temp = head;
        stack<int> st;
        long long number = 0;
        while (temp != NULL)
        {
            number = number * 10 + temp->data;
            temp = temp->next;
        }
        number += 1;
        while (number != 0)
        {
            int rem = number % 10;
            st.push(rem);
            number = number / 10;
        }
        int headwiser = st.top();
        st.pop();
        Node *newhead = new Node(headwiser);
        Node *mover = newhead;
        while (!st.empty())
        {
            Node *temp = new Node(st.top());
            st.pop();
            mover->next = temp;
            mover = temp;
        }
        return newhead;
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
    /*T.C -> (3N)*/
    static Node *TwoBruteAdder(Node *head)
    {
        if (head == NULL)
            return NULL;
        int carry = 1;
        Node *newhead = RecursiveReverser(head);
        Node *temphead = newhead;
        while (temphead != NULL)
        {
            temphead->data = temphead->data + carry;
            if (temphead->data < 10)
            {
                carry = 0;
                break;
            }
            else
            {
                temphead->data = 0;
                carry = 1;
            }
            temphead = temphead->next;
        }
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            head = RecursiveReverser(newhead);
            newNode->next = head;
            return newNode;
        }
        return RecursiveReverser(newhead);
    }
    // Recursive function to add one from least significant digit (rightmost node)
    int addOneUtil(Node *node)
    {
        // Base case: when reaching beyond last node, return carry = 1
        if (!node)
            return 1;

        // Recurse to the end
        int carry = addOneUtil(node->next);
        int sum = node->data + carry;
        if (sum < 10)
        {
            return 0;
            node->data = 0;
        }
        // Return new carry
        return 1;
    }

    // Function to add one to the number represented by the linked list
    Node *addOne(Node *head)
    {
        // Perform recursive addition
        int carry = addOneUtil(head);

        // If carry remains after processing the head, create a new head node
        if (carry)
        {
            Node *newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};
