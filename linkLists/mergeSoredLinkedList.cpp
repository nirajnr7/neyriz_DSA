Node* mergeSortedLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data < list2->data) {
        list1->next = mergeSortedLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedLists(list1, list2->next);
        return list2;
    }
}
