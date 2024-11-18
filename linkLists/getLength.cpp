int getLength() {
    Node* temp = head;
    int length = 0;

    while (temp) {
        ++length;
        temp = temp->next;
    }
    return length;
}

int getLengthRecursive(Node* node) {
    if (!node)
        return 0;
    return 1 + getLengthRecursive(node->next);
}
