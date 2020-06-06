#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() 
        :val(0), next(NULL) {
    }
    ListNode(int x)
        :val(x), next(NULL) {
    }
    ListNode(int x, ListNode* n)
        :val(x), next(n) {
    }
};

/* remove n-th element starting from the end */
/* 1->2->3->4->NULL, n = 2, remove 3 ==> 1->2->4->NULL */

/* two pass solution: find the depth first, then iterate based on new length */
ListNode* remove_one(ListNode* head, int n) {
    int len = 0;
    ListNode* first = head;
    ListNode* dummy = new ListNode; //important: if the first one is removed, a reference is needed
    dummy->next = head;
    while (first != NULL) {
        ++len;
        first = first->next;
    }
    len -= n;
    first = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    first->next = first->next->next;
    return dummy->next;
}

/* one pass solution: maintain two pointers that are n-elements away */
ListNode* remove_two(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *first = dummy, *second = dummy;
    while (first->next != NULL) {
        first = first->next;
        if (n == 0) {
            second = second->next;
        }
        else {
            --n;
        }
    }
    second->next = second->next->next;
    return dummy->next;
}

