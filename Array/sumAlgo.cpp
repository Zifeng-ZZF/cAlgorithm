#include "sumAlgo.h"
#include <unordered_map>
#include <algorithm>
#include <limits.h>

std::vector<int> twoSum (std::vector<int>& nums, int length, int target)
{
    if (nums.empty() || nums.size() < 2) return {};
    std::vector<int> ans;
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < length; i++)
    {
        int complement = target - nums[i]; // store the matched complement for current element
        if (hashMap.find(nums[i]) != hashMap.end()) // found and other element to be the complement of previous element
        {
            ans.push_back(complement);
            ans.push_back(nums[i]);
            return ans;
        }
        hashMap[complement] = i;
    }
    return ans;
}


/*
Find all the combinations of three numbers such that their sum is zero
*/
std::vector<std::vector<int>> threeSum (std::vector<int>& nums, int length)
{
    if (nums.empty() || nums.size() < 3) return {};
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());  
    for (int i = 0; i < length - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = length - 1;
        for (int n = i + 1; n < j;) // not "n < length - 1", j will be changed internally
        {
            int sum = nums[i] + nums[j] + nums[n];
            if (sum == 0)
            {
                std::vector<int> row {nums[i], nums[j], nums[n]};
                ans.push_back(row);
                // move the two pointers accordingly
                n++;
                j--;
                while (nums[n] == nums[n - 1] && n < j) n++; // skip same smaller element
                while (nums[j] == nums[j + 1] && n < j) j--; // skip same larger element
            }
            else if (sum < 0)
                n++;
            else
                j--;
        }
    }
    return ans;
}

/*
Given a set of numbers and a target sum. Find three numbers from the set such that
their sum is closest to the target number. Return the sum of these three numbers.
*/
int threeSumCloset (std::vector<int>& nums, int length, int target)
{
    if (nums.empty() || nums.size() < 3) return 0;

    int ans;
    int min_diff = INT_MAX;
    if (min_diff < 0) min_diff *= -1;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = length - 1;
        int n = i + 1;
        while (n < j)
        {
            int temp_ans = nums[i] + nums[j] + nums[n];
            int temp_min = temp_ans - target;
            if (temp_min == 0)
            {
                return temp_ans;
            }
            else if(temp_min < 0)
            {
                temp_min *= -1;
                n++;
                while (n < j && nums[n] == nums[n - 1]) n++;
            }
            else
            {
                j--;
                while (j > n && nums[j] == nums[j + 1]) j--;
            }

            if (temp_min < min_diff)
            {
                min_diff = temp_min;
                ans = temp_ans;
            }
        }
    }
    return ans;
}

/*
Given an array nums of n integers and an integer target, are there
elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
*/
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    if (nums.empty() || nums.size() < 4) return {};
    int length = nums.size();
    std::vector<std::vector<int>> ans;



    return ans;
}