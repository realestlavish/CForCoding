#include <iostream>
#include <vector>
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

class DLL
{
public:
    static Node *DLLConverter(vector<int> arr)
    {
        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }

    static Node *HeadDeleter(Node *head)
    {
        if (head->next == NULL || head == NULL)
            return NULL;
        Node *prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        free(prev);
    }

    static Node *TailDeleter(Node *head)
    {
        if (head->next == NULL || head == NULL)
            return NULL;
        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        Node *nwtail = tail->back;
        nwtail->next = nullptr;
        tail->back = nullptr;
        free(tail);
        return head;
    }

    static Node *KthElDeleter(Node *head, int k)
    {
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            if (temp->data == k)
                break;
            temp = temp->next;
        }
        Node *prev = temp->back;
        Node *front = temp->next;

        if (prev == NULL || front == NULL)
        {
            return NULL;
        }
        else if (prev == NULL)
            HeadDeleter(head);
        else if (front == NULL)
            TailDeleter(head);
        else
        {
            prev->next = front;
            front->back = prev;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
        }
        return head;
    }

    static void nodeDeleter(Node *temp)
    {
        Node *prev = temp->back;
        Node *front = temp->next;
        if (front == NULL)
        {
            prev->next = nullptr;
            temp->back = nullptr;
            free(temp);
            return;
        }
        prev->next = front;
        front->back = prev;
        temp->next = temp->back = nullptr;
        free(temp);
    }

    static Node *Insertb4Head(Node *head, int val)
    {
        Node *newHead = new Node(val, head, nullptr);
        head->back = newHead;
        return newHead;
    }

    static Node *Insertb4Val(Node *head, int val)
    {
        if (head->next == NULL)
        {
            return Insertb4Head(head, val);
        }

        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        Node *prev = tail->back;
        Node *newNode = new Node(val, tail, prev);
        prev->next = newNode;
        tail->back = newNode;
        return head;
    }

    static Node *Insertb4KNode(Node *head, int val, int k)
    {
        if (k == 1)
        {
            return Insertb4Head(head, val);
        }

        Node *tempo = head;
        int cnt = 0;
        while (tempo != NULL)
        {
            cnt++;
            if (cnt == k)
            {
                break;
            }
            tempo = tempo->next;
        }
        Node *prev = tempo->back;
        Node *newNode = new Node(val, tempo, prev);
        prev->next = newNode;
        tempo->back = newNode;
        return head;
    }

    static Node *Insertb4Node(Node *node, int val)
    {
        Node *prev = node->back;
        Node *nwNode = new Node(val, node, prev);
        node->back = nwNode;
        prev->next = nwNode;
        return nwNode;
    }

    static Node *ReverseingLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *current = head;
        Node *backnode = NULL;
        while (current != NULL)
        {
            backnode = current->back;
            current->back = current->next;
            current->next = backnode;
        }
        return backnode->back;
    }
};

int main()
{
    vector<int> arr = {99, 4, 45, 5};
    Node *head = DLL::DLLConverter(arr);
}