/* find the k most frequent elements in the array, that it is, return an array of the top k */

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/* S1: priority queue: */
/* O(N) = N*logk, (k is the input) */
vector<int> findKMost(vector<int>& nums, int k) {
    /* 1. store the number of appearence of every element using hashmap */
    unordered_map<int, int> countMap;
    for (auto& num : nums) {
        ++countMap[num];
    }

    /* 2. priority_queue to use min heap, with the mimium on the top */
    /* specify the <[element type], [continer type], [comparator]> to specify min heap / max heap */
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> priQu;
    for (auto& pa : countMap) {
        // logk
        // pair is sorted via its first element, so we need to exchange the key & val
        priQu.push({pa.second, pa.first}); 
        if (priQu.size() > k) //pop the minmum while size reach k, so the remainants are the k most biggest number
            priQu.pop();
    }

    /* 3. push the answer into required data structure */
    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        ans[i] = priQu.top().first;
        priQu.pop();
    }
    return ans;
}


/* S2: quickselect */
void quickselect(int l, int r);
int partition(int l, int r, int startIdx);

int startIdx; //starting point of the last k (ascending order)
vector<int> uniqueArr; //unique version of the input
unordered_map<int, int> countMap; //counting the number of appearance of number
vector<int> findkMost(vector<int>& nums, int k) {
    // 1. counting
    for (auto& num : nums)
        countMap[num]++;
    
    // 2. unifying
    for (auto& item : countMap)
        uniqueArr.push_back(item.first);
    
    // 3. quickselect and partition
    int n = uniqueArr.size();
    startIdx = n - k; //position in the uniqueArr
    quickselect(0, n - 1);

    // 4. store the answer
    vector<int> ans;

}

void quickselect (int l, int r) {
    if (l >= r)
        return;
    // picking the middle position as the pivot
    int pivot = l + ((r - l) >> 1);
    // partitioning
    int res = partition(l, r, pivot);
    // quickselect
    if (res == startIdx)
        return;
    else if (res < startIdx)
        quickselect(pivot + 1, r);
    else
        quickselect(l, pivot - 1);
}

int partition(int l, int r, int pivot) {
    int write = l;
    int curr = countMap[uniqueArr[pivot]];
    // put the pivot value to the end of the array
    swap(uniqueArr[pivot], uniqueArr[r]);
    while (l < r) {
        // put all the elements that is smaller than curr (frequencey) from the left, no ordering
        if (countMap[uniqueArr[l]] < curr) {
            if (write != l)
                // swap instead of overwrite
                swap(uniqueArr[write], uniqueArr[l]);
            // increase write index after writing to that position
            ++write;
        }
        ++l;
    }
    // the final write position is the right position for pivot value
    // change it to that position
    swap(uniqueArr[write], uniqueArr[r]);
    return write;
}