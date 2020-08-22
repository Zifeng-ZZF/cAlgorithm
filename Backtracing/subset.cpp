/* Q1: find all the subset of given set with distinct element */
/* 
    Solution space for permutation, combination, and subset:
    Permutation: N!
    Combination: N! / (N -k)!k!
    Subset: 2^N

    Usually can apply same strategy
*/
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

/* S1: backtracing, O(N * 2^N) */
void backtrace(vector<vector<int>>& ans, vector<int>& nums, vector<int> oneans, int len, int idx) {
    ans.push_back(oneans);
    for (int i = idx; i < len; ++i) {
        if (idx > 0 && oneans.back() > nums[i])  //按照一个大小顺序读取就不会出现重复的集合
            continue;
        
        oneans.push_back(nums[i]);
        swap(nums[idx], nums[i]); //remember to swap after pushing in case of repeated reading
        
        backtrace(ans, nums, oneans, len, idx + 1);

        swap(nums[idx], nums[i]);
        oneans.pop_back();
    }
}

vector<vector<int>> subset_backtrace(vector<int>& nums) {
    vector<vector<int>> ans;
    //sort(nums.begin(), nums.end());
    backtrace(ans, nums, {}, nums.size(), 0);
    return ans;
}

/* S1.1: Binary sorted subset */
/* use a bitmask to indicate the presense and absence of a number in the set */
vector<vector<int>> subset_bitmask(vector<int>& nums) {
    int l = nums.size();
    // n = 2 ^ l is the size of solution space for subset
    // pow(a, b) return double thus the conversion
    int n = (int)pow(2, l); 
    vector<vector<int>> ans;
    // if l = 3, then solution space n = 2 ^ 3 = 8
    // i < 8 -> i = 0, 1, 2, 3, 4, 5, 6, 7
    // Its corresponding binary representation:
    // 000, 001, 010, 011, 100, 101, 110, 111
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        // foreach i value, test its binary representation's each bit
        for (int j = 0; j < l; ++j) {
            // 1 << j 不等同于 j << 1。 ’1 << j‘是把1向左移j位，后者则是把j向左移1位。
            // test i with pos
            // pos = 001, 010, 100
            int pos = 1 << j; 
            // remember to add bracket around i & pos
            if ((i & pos) != 0) {
                // j 位置的元素被选中，加入到答案中
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}


/* Q2: subset with duplicate, use set to eliminate it */
void backtrace(vector<vector<int>>&ans, vector<int>& nums, vector<int> oneans, int n, int idx) {
    ans.push_back(oneans);
    // use a hash set to prevent duplicate
    unordered_set<int> used;
    for (int i = idx; i < n; ++i) {
        // prevent duplicate set
        if (idx > 0 && oneans.back() > nums[i])
            continue;

        // prevent duplicate element in a set
        if (idx > 0 && used.find(nums[i]) != used.end())
            continue;
        used.insert(nums[i]);

        oneans.push_back(nums[i]);
        swap(nums[i], nums[idx]); // remember to swap to prevent repeatedly reading the same element
        backtrace(ans, nums, oneans, n, idx  + 1);
        // backtracing
        swap(nums[i], nums[idx]); 
        oneans.pop_back();
    }
}