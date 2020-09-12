/*
    Given an array of non-negative integers, you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Determine if you are able to reach the last index.
*/

#include <iostream>
#include <vector>
using namespace std;

/* S1: Backtracing (TLEX) */
/* Most intuitive brute force: O(2^N) */
/* can be turned into top-down dynamic programming */
bool backtrace(int pos, int n, vector<int>& nums) {
    if (pos >= n)
        return true;
    
    int dist = n - 1 - nums[pos];
    int maxStep = dist > nums[pos] ? nums[pos] : dist;
    for (int i = maxStep; i > 0; --i) {
        if (backtrace(pos + i, n, nums)) //backtracing
            return true;
    }
    return false;
}

bool canJump(vector<int>& nums) {
    return backtrace(0, nums.size(), nums);
}


/* S2: Top-Down Dynamic by adding memoization */
/* Time - O(N^2) ; Space - O(2*N) */
int memo[];

enum {GOOD, BAD, UNKNOWN};

bool dynamicHelper(int pos, int n, vector<int>& nums) {
    if (memo[pos] != UNKNOWN)
        return memo[pos] == GOOD ? true : false;
    int dist = n - 1 - nums[pos];
    int maxStep = dist > nums[pos] ? nums[pos] : dist;
    for (int i = maxStep; i > 0; --i) {
        if (dynamicHelper(pos + i, n, nums)) {
            memo[pos] = GOOD;
            return true;
        }
    }
    memo[pos] = BAD;
    return false;
}

bool canJump2(vector<int>& nums) {
    int n = nums.size();
    memo[n];
    for (int i = 0; i < n; ++i) {
        memo[i] = UNKNOWN;
    }
    memo[n - 1] = GOOD;
    return dynamicHelper(0, n, nums);
}

/* S3: Bottom-Up Dynamic */
/* converting recursion into iterative */
/* save space consumed by stack called: Space - O(N) */
bool canJump3(vector<int>& nums) {
    int n = nums.size();
    bool memo[n];
    for (int i = 0; i < n; ++i)
        memo[i] = false;
    memo[n - 1] = true;

    for (int i = n - 2; i >= 0; --i) {
        int distToEnd = n - 1 - i;
        int furthestStep = nums[i] < distToEnd ? nums[i] : distToEnd;
        for (int j = furthestStep; j > 0; --j) {
            if (memo[i + j]) {
                memo[i] = true;
                break;
            }
        }
    }
    return memo[0];
}


/* S4: Greedy Dynamic */
/* best solution optimized from iterative dynamic programming */
/* as long as one element can jump to the closet & leftmost good node, it can jump to any good node at the right of it, including the final */
/* No extrac space - O(1) */
/* No searching for each step: Time - O(N) */
bool canJump4(vector<int>& nums) {
    int n = nums.size();
    int leftmostGood = n - 1;
    for (int i = n - 2; i >= 0; --i)
        if (i + nums[i] >= leftmostGood)
            leftmostGood = i;
    return leftmostGood == 0;
}
