/* find the k th largest elements in the array */

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/* S1: priority queue: */
/* O(N) = N*logk, (k is the input) */
int findKthLargest(vector<int>& nums, int k) {
    /* by default the comparator is less<T> */
    priority_queue<int> heap;
    int n = nums.size() - k + 1;
    for (auto& num : nums) {
        heap.push(num);
        if (heap.size() > n)
            heap.pop();
    }
    return heap.top();
}

/* S1:quickselect */