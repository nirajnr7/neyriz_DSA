#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Recursive function to reverse the linked list
Node* reverseRecursive(Node* node) {
    if (!node || !node->next)
        return node;

    Node* rest = reverseRecursive(node->next);
    node->next->next = node;
    node->next = nullptr;
    return rest;
}

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Main function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List:" << endl;
    printList(head);

    // Reversing the linked list recursively
    head = reverseRecursive(head);

    cout << "Reversed List:" << endl;
    printList(head);

    return 0;
}
