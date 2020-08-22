/*
    [1, 2 ,3] plus one [1, 2, 4]
    [9, 9, 9] plus one [1, 0, 0, 0]
*/
#include <iostream>
#include <vector>
using namespace std;

/* record carry bit for each position, make use of properties of '/' and '%' */
vector<int> plusOne(vector<int> nums) {
    int carryBit = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        nums[i] += carryBit;
        carryBit = nums[i] / 10; //important step: record the highest-position digit; record if there is carry bit
        nums[i] %= 10;
        if (!carryBit) { // not carry, means no change to higer bit, break the loop
            break;
        }
    }
    if (carryBit) { //check the record of the highest position digit
        nums.insert(nums.begin(), carryBit);
    }
    return nums;
}

/* fastest solution */
/* if current bit is 9, make equal to 0, if not ++ and break; check the final digit, if idx = -1, then the last digit must not be broke */
vector<int> plusOne_two(vector<int> nums) {
    int idx;
    for (idx = nums.size() - 1; idx >= 0; --idx) {
        if (nums[idx] == 9) {
            nums[idx] = 0;
        }
        else {
            ++nums[idx];
            break;
        }
    }
    if (idx < 0) { // if has carry, idx must be lower than 0
        nums.insert(nums.begin(), 1);
    }
    return nums;
}
