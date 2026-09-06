#include <unordered_map>
using namespace std;
class LRUCache
{
    struct Node
    {
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node *> mpp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;
    
    LRUCache(int capacity)
    {
        capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add(Node *newNode)
    {
        Node *temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void update(Node *node)
    {
        remove(node);
        add(node);
    }
    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            update(mpp[key]);
            return mpp[key]->value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            update(mpp[key]);
            mpp[key]->value = value;
            return;
        }
        else
        {
            if (mpp.size() == capacity)
            {
                Node *lru = tail->prev;
                mpp.erase(lru->key);
                remove(lru);
                delete lru;
            }
            add(new Node(key, value));
            mpp[key] = head->next;
        }
    }
};