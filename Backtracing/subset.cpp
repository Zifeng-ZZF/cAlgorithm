/* find all the subset of given set */
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

/* backtracing, O(N * 2^N) */
void backtrace(vector<vector<int>>& ans, vector<int>& nums, vector<int> oneans, int len, int idx) {
    ans.push_back(oneans);
    for (int i = idx; i < len; ++i) {
        if (idx > 0 && oneans.back() > nums[i])  //按照一个大小顺序读取就不会出现重复的集合
            continue;
        
        oneans.push_back(nums[i]);
        swap(nums[idx], nums[i]);
        
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

/* Binary sorted subset */
/* use a bitmask to indicate the presense and absence of a number in the set */
vector<vector<int>> subset_bitmask(vector<int>& nums) {
    int l = nums.size();
    int n = (int)pow(2, l);
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j < l; ++j) {
            int pos = 1 << j; // 1 << j 不等同于 j << 1。 ’1 << j‘是把1向左移j位，后者则是把j向左移1位。
            if ((i & pos) != 0) {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

/* subset with duplicate, use set to eliminate it */
void backtrace(vector<vector<int>>&ans, vector<int>& nums, vector<int> oneans, int n, int idx) {
    ans.push_back(oneans);
    unordered_set<int> used;
    for (int i = idx; i < n; ++i) {
        if (idx > 0 && oneans.back() > nums[i])
            continue;
        if (idx > 0 && used.find(nums[i]) != used.end())
            continue;
            
        used.insert(nums[i]);

        oneans.push_back(nums[i]);
        swap(nums[i], nums[idx]);
        backtrace(ans, nums, oneans, n, idx  + 1);
        swap(nums[i], nums[idx]);
        oneans.pop_back();
    }
}