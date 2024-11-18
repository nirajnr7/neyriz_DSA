bool search(int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}


bool searchRecursive(Node* node, int val) {
    if (!node)
        return false;
    if (node->data == val)
        return true;
    return searchRecursive(node->next, val);
}
