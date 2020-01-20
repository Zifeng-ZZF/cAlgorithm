#include "sumAlgo.h"
#include <unordered_map>

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
        std::cout << hashMap[complement];
    }
    return ans;
}

std::vector<int> threeSum (std::vector<int>& nums, int length, int target)
{

}