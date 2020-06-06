/* merge tow sorted linked list */
struct ListNode {
    int val;
    ListNode* next;
};

/* recursion */
/* faster */
ListNode* merge_one(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }
    else if (l1->val < l2->val) {
        l1->next = merge_one(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge_one(l1, l2->next);
        return l2;
    }
}

/* iteration: dummy and two pointers */
ListNode* merge_two(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode;
    ListNode* prev = dummy;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        }
        else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == nullptr ? l2 : l1;
    return dummy->next;
}