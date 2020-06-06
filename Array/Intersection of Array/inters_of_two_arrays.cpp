#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

/* find the intersection of two arrays */

/* intuitive solution */
vector<int> intersection_one(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& few = nums1.size() < nums2.size() ? nums1 : nums2;
    vector<int>& more = nums1.size() >= nums2.size() ? nums1 : nums2;
    int fsize = few.size(), msize = more.size();
    vector<int> ans;
    for (int i = 0; i < fsize; ++i) {
        for (int j = 0; j < msize; ++j) {
            if (more[j] == few[i]) {
                ans.push_back(few[i]);
                more.erase(more.begin() + j); //erase  in case of repetition.
                --msize; //decrease size in case of exceeding boundary
                break;
            }
        }
    }
    return ans;
}

/* hashtable: count the appearance of number */
vector<int> intersection_two(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> map;
    for (auto& num : nums1) {
        ++map[num];
    }
    for (auto& num : nums2) {
        --map[num];
        if (map[num] >= 0) {
            ans.push_back(num);
        }
    }
    return ans;
}

/* sort and binary search: sort only the longer array, search match of elements in the shorter from the longer sorted array */
/* nlogn */
/* answer to follow up: if the arrays are already sorted */
int find(vector<int>& nums, int val) { //binaray search return the index of the target
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) { //remember to add '='
        int mid = start + (end - start) / 2;
        if (nums[mid] == val) {
            return mid;
        }
        else if (nums[mid] > val) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

vector<int> intersection_three(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    vector<int>& few = nums1.size() < nums2.size() ? nums1 : nums2;
    vector<int>& more = nums1.size() >= nums2.size() ? nums1 : nums2;
    sort(more.begin(), more.end());
    int size = few.size();
    for (int i = 0; i < size; ++i) {
        int res = find(more, few[i]);
        if (res >= 0) {
            more.erase(more.begin() + res); // has to remove, begin() iterator plus the index
            ans.push_back(few[i]);
        }
    }
    return ans;
}

/* sorted arrays, two pointers record */
/* also if the arrays are sorted */
vector<int> intersection_four(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int count1 = 0, count2 = 0; // respectively points to two array's start
    int size1 = nums1.size(), size2 = nums2.size();
    vector<int> ans;
    while (count1 < size1 || count2 < size2) {
        if (nums1[count1] == nums2[count2]) {
            ans.push_back(nums1[count1]);
            ++count1;
            ++count2;
        }
        else if (nums1[count1] > nums2[count2]) {
            ++count2;
        }
        else {
            ++count1;
        }
    }
    return ans;
}

/* Follow up: What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once? */
/*
    1. if nums1 fits in the memory, then read chuncks of array that fit into the memory, and count the intersection
    2. if both are too large to fit in the memory, use Map-Reduce technique.
    3. if both are too large, use "External sort" respectively, then read certain amount of data into memory. Use the above two-pointers technique
*/