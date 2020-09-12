#include <vector>
#include <iostream>
using namespace std;

void quickSort(vector<int>& nums, int left, int right) {
    int l = left, r = right;
    if (r <= l)
        return;
    int pivot = l + ((r - l) >> 1);
    int marker = nums[pivot];
    // important: swap the pivot to the end
    // because the pivot will be swapping throughout the process and finally reach its correct position
    // since we start from the left to find the larger element than pivot, we need to place it at the rightmost position beforehand
    swap(nums[pivot], nums[r]);
    while (l < r) {
        //from left find the ones larger than pivot, exchange to the back
        while (nums[l] <= marker && l < r)
            ++l;
        if (l < r) 
            swap(nums[l], nums[r]);

        //from right find the ones smaller than the pivot, exchange to the front
        while (nums[r] >= marker && l < r) 
            r--;
        if (l < r)
            swap(nums[l], nums[r]);
    }
    // when l == r, pivot value is at its right position
    quickSort(nums, left, l - 1);
    quickSort(nums, l + 1, right);
}

int main() {
    vector<int> nums = {4, 3, 2, 1, 9, 8, 7, 6};
    int n = nums.size();
    quickSort(nums, 0, n - 1);

    for (auto& num : nums)
        cout << num << "\n";
}