struct ListNode {
    int val;
    ListNode* next;
};

/* recursion: fastest */
/* find the new head first, then rotate the pointing arrow */
ListNode* reverse_one(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newHead = reverse_one(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

/* iteration: two pointers and a temp node */
ListNode* reverse_two(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* first = head, * second = nullptr, * temp = nullptr;
    while (first != nullptr) {
        temp = first;
        first = first->next;
        temp->next = second;
        second = temp;
    }
    return second;
}