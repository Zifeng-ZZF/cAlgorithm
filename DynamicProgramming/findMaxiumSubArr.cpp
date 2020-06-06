#include <vector>
#include <climit>
using namespace std;

/* find the contigent subarray that has the maximum sum , return the max sum*/

/* 1. dynamic programing */
/* by checking the previous element's value, we calculate the maximum sum of two contigent elements */
/* record the max sum of the iterated elemts at the current elements, so the when we go to next elemnts we know the previous contigent result */
int maxSumSubArr_one(vector<int>& nums) {
    int maxSum = nums[0], n = nums.size();
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] > 0) {
            nums[i] = nums[i] + nums[i - 1];
        }
        maxSum = max(maxSum, nums[i]);
    }
    return maxSum;
}

/* divide and conqur 分治 */
/* solve sub-problems, same as merge sort */
/* steps of divide and conquer: 
    1. define base case
    2. split the problem into sub-problems and solve recursively
    3. merge the solutions of sub-problems into the final solutions
*/
int findCrossSum(vector<int>& nums, int left, int right, int mid) {
    if (left == right) {
        return nums[left];
    }
    int cur = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= 0; ++i) {
        cur += nums[i];
        leftSum = max(leftSum, cur);
    }

    cur = 0;
    int rightSum = INI_MIN;
    for (int i = mid + 1; i <= right; ++i) {
        cur += nums[i];
        rightSum = max(rightSum, cur);
    }
    return leftSum + rightSum;
}

int helper(vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    int mid = left + (right - left) / 2;
    int leftSum = helper(nums, left, mid);
    int rightSum = helper(nums, mid + 1, right);
    int crossSum = findCrossSum(nums, left, right, mid);
    return max(max(leftSum, rightSum), crossSum);
}

int maxSumSubArr_two(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

/* greedy algorithm */
/* record the current point maximum, and compare with the all-time maximum */
int maxSumSubArr_three(vector<int>& nums) {
    int n = nums.size();
    int cur = nums[0], maximum = nums[0];
    for (int i = 1; i < n; ++i) {
        cur = max(nums[i], cur + nums[i]);
        maxium = max(maximum, cur);
    }
    return maximum;
}