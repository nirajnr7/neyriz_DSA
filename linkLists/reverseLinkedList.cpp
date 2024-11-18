#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to insert a new node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display the linked list
    void display() const {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;  // Save the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr;       // Move 'prev' forward
            curr = next;       // Move 'curr' forward
        }

        head = prev;  // Update the head to the new first node
    }
};

// Main function to demonstrate the implementation
int main() {
    LinkedList list;

    // Adding elements to the list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    // Displaying the list
    cout << "Original List:" << endl;
    list.display();

    // Reversing the list
    list.reverse();

    // Displaying the reversed list
    cout << "Reversed List:" << endl;
    list.display();

    return 0;
}
