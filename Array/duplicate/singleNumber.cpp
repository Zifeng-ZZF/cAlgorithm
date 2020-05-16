#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/* there is one unqiue number in the vector, the others appear exactly twice, find the unique one */

/*  Method 1:
    using hash-table to count the appearence of each elements
    first-time show-up needs initialization
    this is a common solution even the others appear not merely twice
*/
int singleNum_one(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, int> hMap;
    for (int i = 0; i < size; ++i) {
        if (hMap.find(nums[i]) == hMap.end()) // find(); average case O(1), worse case O(n)
            hMap[nums[i]] = 1;
        else
            ++hMap[nums[i]];
    }

    for (auto& item : hMap) {
        if (item.second == 1)
            return item.first;
    }
    return 0;
}

/*  Method 2:
    math : 
        input: ( a, a, b, b, c)
        2 * ( a + b + c) - ( a + a + b + b + c) = c;
*/
int singleNum_second(vector<int>& nums) {
    unordered_set<int> mSet;
    int sumOfSet = 0, sumOfVec = 0;
    for (auto& num : nums) {
        if (mSet.find(num) == mSet.end()) {
            mSet.insert(num);
            sumOfSet += num;
        }
        sumOfVec += num;
    }
    return (2 * sumOfSet - sumOfVec);
}

/*  Method 3:
    bit manipulation: XOR exchangable operants order
    a XOR b XOR a = a XOR a XOR b = 0 XOR b = b
*/
int singleNum_third(vector<int>& nums) {
    int ans = 0;
    for (auto& num : nums) {
        ans ^= num;
    }
    return ans;
}

int main()
{

}