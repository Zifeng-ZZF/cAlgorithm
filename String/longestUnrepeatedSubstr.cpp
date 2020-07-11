#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/* find the length of the longest unrepeated substring of a given string */

/* hashing and brute force */
int findLongest_one(string s) {
    if (s.empty()) {
        return 0;
    }
    int n = s.length(), maxlen = 0;
    unordered_set<int> mset;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (mset.find(s[j]) != mset.end()) {
                maxlen = max(maxlen, (int)mset.size());
                mset.clear();
            }
            mset.insert(s[j]);
        }
        if (!mset.empty()) {
            break;
        }
    }
    return max(maxlen, (int)mset.size());
}

/* sliding window and hash set */
/* worse case : O(2n) */
int findLongest_two(string s) {
    int n = s.length(), i = 0, j = 0, maxlen = 0;
    unordered_set<char> mset;
    while (i < n && j < n) {
        if (mset.find(s[j]) == mset.end()) {
            mset.insert(s[j++]);
            maxlen = max(maxlen, j - i);
        }
        else {
            mset.erase(s[i++]);
        }
    }
    return maxlen;
}

/* sliding window optimized with hash map */
int findLongest_three(string s) {
    unordered_map<char, int> mmap;
    int i = 0, j = 0, n = s.length();
    int maxlen = 0;
    while (j < n) { //worse case is now O(n)
        if (mmap.find(s[j]) == mmap.end()) {
            mmap[s[j]] = j;
            ++j;
            maxlen = max(maxlen, j - i);
        }
        else {
            i = max(i, mmap[s[j]] + 1);
            mmap.erase(s[j]);
        }
    }
    return maxlen;
}

/* sliding window with hash array */
int findLongest_four(string s) {
    vector<int> hash(128, -1); //vector with -1 to mark no-pos
    int i = 0, j = 0, n = s.length();
    int maxlen = 0;
    while (j < n) {
        if (hash[s[j]] == -1) { //if no-pos, no existed
            hash[s[j]] = j; //record the position
            ++j;
            maxlen = max(maxlen, j - i); //record the max length
        }
        else {
            i = max(i, hash[s[j]] + 1); // move the largest i position to avoid repeatition
            hash[s[j]] = -1; // re-mark as no-pos
        }
    }
    return maxlen;
}