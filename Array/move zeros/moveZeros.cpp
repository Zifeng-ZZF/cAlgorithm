/*
    move all the zeros to the end
    all the non-zero element stay in the same order
*/
#include <vector>
using namespace std;

/* intuitive solution: make use of iterator and vector operations */
void moveZero_one(vector<int> nums) {
    vector<int>::iterator beg = nums.begin();
    vector<int>::iterator end = nums.end();
    while (beg != end) {
        if (*beg == 0) {
            nums.erase(beg);
            nums.push_back(0);
            --end;
        }
        else {
            ++beg;
        }
    }
}

/* without using iterator: record number of zero, need extra O(n) space */
void moveZero_two(vector<int> nums) {
    int zeroCount = 0, size = nums.size();
    vector<int> temp;

    //record number of zeros
    for (int i = 0; i < size; ++i) {
        if (nums[i] == 0) {
            ++zeroCount;
        }
    }

    //save non-zeros in original order to temp
    for (int i = 0; i < size; ++i) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    //append the zeros
    for (int i = 0; i < zeroCount; ++i) {
        temp.push_back(0);
    }

    //update the original nums
    for (int i = 0; i < size; ++i) {
        nums[i] = temp[i];
    }
}

/* without using iterator: O(1) space, use an extra pointer to indicate non-zeros */
/* fastest */
void moveZero_three(vector<int> nums) {
    int lastNonZero = 0, size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (nums[i] != 0) {
            if (i == lastNonZero) {
                ++lastNonZero;
                continue;
            }
            nums[lastNonZero] = nums[i];
            nums[i] = 0;
            ++lastNonZero;
        }
    }
}



