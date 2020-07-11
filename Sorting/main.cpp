#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubbleSort(int arr[], int length)
{
    if (length <= 1)
        return;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertSort(int arr[], int length)
{
    if (length <= 1)
        return;
        
    for (int i = 1; i < length; i++)
    {
        // must compare starting from the last/newest one
        for (int j = i; j > 0; j--) 
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high)
{
    if ((high - low) <= 0)
    {
        return;
    }
    int i = low;
    int j = high;
    int marker = arr[high];
    while (i < j)
    {
        while (arr[i] <= marker && i < j) i++;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        while (arr[j] >= marker && i < j) j--;
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

/* merge sort */
void merge(vector<int>& nums, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    int i = l, j = m + 1; //start of two sorted part
    while (i <= m && j <= r) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            ++i;
        }
        else {
            temp.push_back(nums[j]);
            ++j;
        }
    }
    while (i <= m) {
        temp.push_back(nums[i]);
        ++i
    }
    while (j <= r) {
        temp.push_back(nums[j]);
        ++j;
    }
    for (int k = l; k <= r; ++k) {
        nums[k] = temp[k - l];
    }
}
void helper(vector<int>& nums, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        helper(nums, l, mid); //left-included
        helper(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
}
void mergeSort(vector<int>& nums) {
    helper(nums, 0, nums.size() - 1); //left-included
}



int main ()
{
    int arr[10]{2, 3, 10, 1, 4, 7, 6, 9, 8, 5};

    // cannot be called inside a function to return the length
    // array as parameter is a reference which means it is an integer long
    // it has to be calc in the area where it is defined
    int len = (int)sizeof(arr) / sizeof(arr[0]);

    // quickSort(arr, 0, len(arr) - 1);
    // bubbleSort(arr, len);
    insertSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
}