#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

/* use an extra vector to store the elements, then validate using two pointers */
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    vector<int> vals;
    while (head != nullptr) {
        vals.push_back(head->val);
        head = head->next;
    }
    int size = vals.size();
    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        if (vals[i] != vals[j]) {
            return false;
        }
    } 
    return true;
}


/* using a global variable to record the first, and use recursion */
ListNode* front;
bool helper(ListNode* cur) {
    if (cur != nullptr) {
        if (!helper(cur->next)) {
            return false;
        }
        if (cur->val != front->val) {
            return false;
        }
        front = front->next;
    }
    return true;
}
bool isPalindrone_two(ListNode* head) {
    front = head;
    return helper(head);
}


/* reverse the second half and compare with the first half */
/* fastest, no extra space solution */
ListNode* reverse(ListNode* head) {
    ListNode* temp = nullptr, * prev = nullptr;
    while (head != NULL) {
        temp = head;
        head = head->next;
        temp->next = prev;
        prev =temp;
    }
    return prev;
}
bool isPalindrone_three(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    /* 1. find the length */
    int len = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        ++len;
        temp = temp->next;
    }

    /* 2. find the node before the start node of the second half */
    len = (len + 1) / 2 - 1; //the cnt of step to move
    temp = head;
    while (len > 0) {
        temp = temp->next;
        --len;
    }

    /* 3. reverse the second half and store its head */
    temp = reverse(temp->next);

    /* 4. compare the two half */
    while (temp != NULL) {
        if (temp->val != head->val) {
            return false;
        }
        temp = temp->next;
        head = head->next;
    }
    return true;
}