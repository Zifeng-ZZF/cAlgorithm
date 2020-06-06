// find circle in linked list
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

/* hashing, O(n) space */
bool hasCircle(ListNode* head) {
    unordered_set<ListNode *> set;
    while (head != NULL) {
        if (set.find(head) != set.end()) {
            return false;
        }
        set.insert(head);
        head = head->next;
    }
    return true;
}

/* fast-slow two pointers, O(1) space and faster */
bool hasCircle_two(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    ListNode* slow = head, * fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}