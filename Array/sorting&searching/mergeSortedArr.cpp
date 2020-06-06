#include <vector>
using namespace std;

/*
    Merge two sorted arrays
    The first array has enough space to include the second array
    merge the second into the first to get a sorted new array
*/

/* merging and sorting: O(log(m + n)) fastest */
void mergeSorted(vector<int>& nums1, int m, vecotr<int>& nums2, int n) {
    for (int i = m, j = 0; i < m + n; ++i, ++j) {
        nums1[i] = nums2[j];
    }
    sort(nums1.begin(), nums1.end());
}

/* two pointers and extra O(m) space , O(m + n) */
void mergeSorted_two(vector<int>& nums1, int m, vecotr<int>& nums2, int n) {
    int i = 0, j = 0, k = 0;
    vector<int> nums3 = nums1;
    while (i < m && j < n) {
        if (nums3[i] < nums2[j]) {
            nums1[k++] = nums3[i++];
        }
        else {
            nums1[k++] = nums2[j++];
        }
    }
    while (i < m) {
        nums1[k++] = nums3[i++];
    }
    while (j < n) {
        nums1[k++] = nums2[j++];
    }
}

/* two pointers from backwards, O(1) space */
void mergeSorted_three(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }
    while (i >= 0) {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
