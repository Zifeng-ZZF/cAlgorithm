#include <vector>
using namespace std;

/*
    Find the longest increasing subsequence of a unsorted array. No need to be contigent
    Do it in O(n^2), and optimize to O(n*logn)
*/

/* dynamic programming */
/* each element of dp array represents the max possible length of a sequence that include the element so far */
/* thus the last elements dp[n - 1] is not the final answer but the max length of the sequence that include the final element */
/* then we need a variable to record the max length of all elements in the process */
/* O(n^2) O(n) */
int myLIS_one(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxval = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxval = max(maxval, dp[i]);
    }
    return maxval;
}

/* dynamic programming with Binary Search */
/* O(n*logn) fastest */
/* form a longest sequence and return its size, dp here represents the sequence */
/* variant of binary search to find the position at right most of the dp array */ 
int binHelper(vector<int>& dp, int left, int right, int target) {
    int index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target <= dp[mid]) {
            index = mid; //返回较大的index
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return index; 
}

int myLIS_two(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int n = nums.size(), idx = 0;
    vector<int> dp(n, INT_MAX);
    for (auto& num : nums) {
        int p = binHelper(dp, 0, idx, num);
        dp[p] = num;
        if (p == idx) {
            ++idx;
        }
    }
    return idx;
}

/* dynamic with binary search, and lower_bound function */
/* lower_bound: Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val. */
/* 找到第一个大于等于指定值的迭代器，如果没有大于等于指定值，则返回last */
int myLIS_three(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MAX);
    for (auto& num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num); //O(logN)e
        if (it != dp.end()) {
            *it = num;
        }
        else {
            dp.push_back(num);
        }
    }
    return dp.size();
}