#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int val, int pos) {
	    Node* newNode = new Node(val);

	    if (pos == 1) {
	        newNode->next = head;
	        head = newNode;
	        return;
	    }

	    Node* temp = head;
	    for (int i = 1; i < pos - 1 && temp; ++i) {
	        temp = temp->next;
	    }

	    if (!temp) {
	        cout << "Position out of bounds." << endl;
	        return;
	    }

	    newNode->next = temp->next;
	    temp->next = newNode;
	}

	void deleteAtPosition(int pos) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
    
    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtPosition(20, 1);
    list.insertAtPosition(10, 2);
    list.insertAtPosition(30, 2);
    list.insertAtPosition(40, 3);
    list.deleteAtPosition(3);
    list.display(); // Output: 20 -> 10 -> 30 -> NULL

    return 0;
}