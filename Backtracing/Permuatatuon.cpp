/* 排列Permutation: given n-long array of distinct number and list all the permutation */
#include <vector>
#include <unordered_set>
using namespace std;

/* backtracing by swaping the first and the current, and move forward */
void helper(vector<vector<int>>& ans, vector<int> nums, int n, int idx) {
    //当头部为最后一个的时候，自动成为答案的一部分，并且该单个答案已经达成，加入全局solution
    if (idx == n - 1) {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < n; ++i) {
        //把当前项移到最前方，成为答案的一部分
        swap(nums[idx], nums[i]);
        //将新的头部和修改过的单个不完全答案传入递归，并且参数回溯idx
        helper(ans, nums, n, idx + 1);
        //回溯到上一个状态
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permutation(vector<int> nums) {
    vector<vector<int>> ans;
    helper(ans, nums, nums.size(), 0);
    return ans;
}


/* permuation that containes possible duplicates */
/* backtracing and local hashset */
void helper(vector<vector<int>>& ans, vector<int> nums, int n, int idx) {
    //当头部为最后一个的时候，自动成为答案的一部分，并且该单个答案已经达成，加入全局solution
    if (idx == n - 1) {
        ans.push_back(nums);
        return;
    }

    unordered_set<int> used;
    for (int i = idx; i < n; ++i) {
        if (used.find(nums[i]) != used.end()) 
            continue;
        used.insert(nums[i]);
        //把当前项移到最前方，成为答案的一部分
        swap(nums[idx], nums[i]);
        //将新的头部和修改过的单个不完全答案传入递归，并且参数回溯idx
        helper(ans, nums, n, idx + 1);
        //回溯到上一个状态
        swap(nums[idx], nums[i]);
    }
}