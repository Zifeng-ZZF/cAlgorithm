#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/* hashMap count appearance */
int firstUnique_one(string s) {
    unordered_map<char, int> cmap;
    for (auto& ch : s) {
        ++cmap[ch];
    }
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (cmap[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}


/* int array count appearance */
/* faster than hashMap */
int firstUnique_two(string s) {
    vector<int> count(26, 0);
    for (auto& ch : s) {
        ++count[ch - 'a'];
    }
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
