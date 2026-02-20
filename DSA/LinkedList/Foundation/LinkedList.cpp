#include <iostream>
#include <vector>
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

class LinkedList
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

    static bool SearchingofEl(Node *head, int val)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Deletion in LL
    static Node *DeleteHead(Node *head)
    {
        if (head == nullptr)
            return head;

        Node *temp = head;
        head = head->next;
        delete temp; // Free memory in C++, no need of this statement in Java as it has Garbage Collector. it will automatically delete.
        return head;
    }

    static Node *DeleteTail(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return nullptr;
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;

        return head;
    }

    static Node *DeleteK(Node *head, int k)
    {
        if (head == NULL)
            return NULL;
        if (k == 1)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return head;
        }
        Node *prev = NULL;
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            if (cnt == k)
            {
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }

    static Node *DeleteEl(Node *head, int el)
    {
        if (head == NULL)
            return NULL;
        if (head->data == el)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return head;
        }
        Node *prev = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == el)
            {
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }

    // Insertion in  LL
    static Node *InsertEl(Node *head, int el)
    {
        return new Node(el, head);
    }

    static Node *InsertElatTail(Node *head, int el)
    {
        if (head = NULL)
            return new Node(el);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(el);
        temp->next = newNode;
        return head;
    }

    static Node *InsertatK(Node *head, int el, int k)
    {
        if (head == NULL)
        {
            if (k == 1)
            {
                return new Node(el);
            }
            else
                return head;
        }
        if (k == 1)
            return new Node(el, head);
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            if (cnt == k - 1)
            {
                Node *x = new Node(el, temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }

    static Node *InsertbeforeK(Node *head, int el, int val)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->data == val)
            return new Node(el, head);
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == val)
            {
                Node *x = new Node(el, temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    vector<int> arr = {99, 4, 45, 5};
    Node *head = LinkedList::LinkedListTraversing(arr);

    cout << head->data << endl;

    int length = LinkedList::LengthofLL(head);
    cout << length << endl;

    bool search = LinkedList::SearchingofEl(head, 9786);
    cout << (search ? "true" : "false");
}