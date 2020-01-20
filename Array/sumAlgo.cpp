#include "sumAlgo.h"
#include <unordered_map>
#include <algorithm>

std::vector<int> twoSum (std::vector<int>& nums, int length, int target)
{
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
    find all the combinations of three numbers such that their sum is zero
*/
std::vector<std::vector<int>> threeSum (std::vector<int>& nums, int length)
{
    std::vector<std::vector<int>> ans;
    if (length <= 2)
    {
        return ans;
    }
    std::sort(nums.begin(), nums.end());  
    for (int i = 0; i < length - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
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
            {
                n++;
            }
            else
            {
                j--;
            }
        }
    }
    return ans;
}


std::vector<int> threeSumCloset (std::vector<int>& nums, int length, int target)
{
    std::vector<int> ans;
    
    return ans;
}