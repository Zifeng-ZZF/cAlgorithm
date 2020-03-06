#include <iostream>
#include <vector>
#include <bitset>

/**
 *  bitmap sort 适用于对大量正整型数进行排序、去重的高效方法
 *  Time complexity: O(n)
 *  相比外部归并节省空间，不必频繁的IO。
**/

void bitMapSort(std::vector<int>& nums, int range)
{
    std::vector<bool> bitmap;
    for (int i = 0; i < nums.size(); i ++)
    {
        bitmap[nums[i]] = true;
    }
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        if(bitmap[i])
        {
            nums[j] = i;
            j++;
        }
    }
}

void bitMapSort2(std::vector<int>& nums, int range)
{
    std::bitset<1024> bitmap;
    for (int i = 0; i < nums.size(); i++)
    {
        bitmap.set(nums[i]);
    }
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        if(bitmap.test(i))
        {
            nums[j] = i;
            j++;
        }
    }
} 

void bitMapSort3(std::vector<int>& nums, int range)
{
    const int RADIX = sizeof(int) * 8; // 32bits-integer
    std::vector<int> bitmap;
    for (int i = 0; i < nums.size(); i++)
    {
        // put the value from nums into bitmap with the right order
        // bitmap[nums[i] / RADIX] : determines which chunk of bit is being accessed
        // (nums[i] % RADIX) : determines the distance to move the '1' within the range of a chunk
        bitmap[nums[i] / RADIX] = bitmap[nums[i] / RADIX] | 1 << (nums[i] % RADIX);
    }
    int k = 0;
    for (int i = 0; i < range; i++)
    {
        for (int j = 0; j < RADIX; j++)
        {
            if ((bitmap[i] & 1 << j) > 0)
            {
                nums[k] = RADIX * i + j;
                k++;
            }
        }
    }
}