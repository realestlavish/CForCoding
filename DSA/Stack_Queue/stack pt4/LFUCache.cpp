#include <unordered_map>
using namespace std;

class LFUCache
{
    struct Node
    {
        int key;
        int value;
        int freq;

        Node *next;
        Node *prev;

        Node(int k, int v)
        {
            key = k;
            value = v;
            freq = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    struct List
    {
        int size;

        Node *head;
        Node *tail;

        List()
        {
            head = new Node(0, 0);
            tail = new Node(0, 0);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void add(Node *node)
        {
            Node *temp = head->next;

            head->next = node;
            node->prev = head;

            node->next = temp;
            temp->prev = node;

            size++;
        }

        void removeNode(Node *node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            size--;
        }

        Node *removeLast()
        {
            if (size == 0)
                return nullptr;

            Node *node = tail->prev;

            removeNode(node);

            return node;
        }
    };

    // key -> Node
    unordered_map<int, Node *> keyNode;

    // frequency -> Doubly Linked List
    unordered_map<int, List *> freqListMap;

    int maxSizeCache;
    int minFreq;
    int curSize;

public:

    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    int get(int key)
    {
        // Key doesn't exist
        if (keyNode.find(key) == keyNode.end())
        {
            return -1;
        }

        Node *node = keyNode[key];

        // Update frequency
        updateFreqListMap(node);

        return node->value;
    }

    void updateFreqListMap(Node *node)
    {
        int oldFreq = node->freq;

        // Remove node from old frequency list
        freqListMap[oldFreq]->removeNode(node);

        // If this was the last node
        // with minimum frequency
        if (oldFreq == minFreq &&
            freqListMap[oldFreq]->size == 0)
        {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Create list if it doesn't exist
        if (freqListMap.find(node->freq) == freqListMap.end())
        {
            freqListMap[node->freq] = new List();
        }

        // Add node to new frequency list
        freqListMap[node->freq]->add(node);
    }

    void put(int key, int value)
    {
        // Capacity is zero
        if (maxSizeCache == 0)
            return;

        // Key already exists
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];

            node->value = value;

            updateFreqListMap(node);

            return;
        }

        // Cache is full
        if (curSize == maxSizeCache)
        {
            // Get least frequently used list
            List *list = freqListMap[minFreq];

            // Remove least recently used node
            Node *node = list->removeLast();

            // Remove from hashmap
            keyNode.erase(node->key);

            delete node;

            curSize--;
        }

        // Create new node
        Node *newNode = new Node(key, value);

        // New nodes always have frequency 1
        minFreq = 1;

        // Create frequency-1 list if needed
        if (freqListMap.find(1) == freqListMap.end())
        {
            freqListMap[1] = new List();
        }

        // Add node to frequency-1 list
        freqListMap[1]->add(newNode);

        // Add to hashmap
        keyNode[key] = newNode;

        curSize++;
    }
};