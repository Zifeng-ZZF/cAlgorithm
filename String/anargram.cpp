#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

/* use built-in hash table */
bool isAnargram_one(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        ++smap[s[i]];
        ++tmap[t[i]];
    }
    for (auto& item : smap) {
        if (item.second != tmap[item.first]) {
            return false;
        }
    }
    return true;
}

/* use vector/array to do the hashing */
bool isAnargram_two(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    vector<int> count(26, 0);
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        ++count[s[i] - 'a'];
        --count[t[i] - 'a'];
    }
    for (int i = 0; i < len; ++i) {
        if (count[s[i] - 'a']) {
            return false;
        }
    }
    return true;
}

/* speed up ? */
static int x = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();