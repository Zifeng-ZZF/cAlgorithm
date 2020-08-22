/* find the k most frequent elements in the array, that it is, return an array of the top k */

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/* S1: priority queue: */
vector<int> findKMost(vector<int>& nums, int k) {
    /* 1. count the appearence of every element using hashmap */
    unordered_map<int, int> countMap;
    for (auto& num : nums) {
        ++countMap[num];
    }

    /* 2. priority_queue to use min heap, with the mimium on the top */
    /* specify the <[element type], [continer type], [comparator]> to specify min heap / max heap */
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> priQu;
    for (auto& pa : countMap) {
        priQu.push(pa);
        if (priQu.size() > k) //pop the minmum while size reach k, so the remainants are the k most biggest number
            priQu.pop();
    }

    /* 3. push the answer into required data structure */
    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        ans[i] = priQu.top().first;
    }
    return ans;
}


/* S2: quickselect */
void quickselect(int l, int r, int index, unordered_map<int, int>& countMap);
void partition(int l, int r, int pivot, unordered_map<int, int>& countMap);

void findkMost(vector<int>& nums, int k) {

}