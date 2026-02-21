#include <bits/stdc++.h> 
using namespace std;

// Node class represents a linked list node
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Solution class to hold sorting function
class Solution {
public:
    // Function to sort the linked list
    Node* sortLL(Node* head) {
        // Vector to store node values
        vector<int> arr;

        // Pointer to traverse the list
        Node* temp = head;

        // Traverse and push values into vector
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Reassign sorted values to list nodes
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->data = arr[i];
            temp = temp->next;
        }

        // Return head of sorted list
        return head;
    }
};

// Function to print linked list
void printLinkedList(Node* head) {
    // Pointer to traverse list
    Node* temp = head;

    // Traverse and print values
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    // Print original list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Create Solution object
    Solution obj;

    // Sort the linked list
    head = obj.sortLL(head);

    // Print sorted list
    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
