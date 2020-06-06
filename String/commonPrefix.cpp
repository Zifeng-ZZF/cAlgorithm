#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* 
    Longest common prefix: find the longest prefix of an array of strings
*/

/* hasing: time: O(m * n), space O(m) */
string longestPre(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    int len = strs[0].length(), n = strs.size();;
    for (auto& str : strs) {
        if (str.length() < len) {
            len = str.length();
        }
    }

    string ans;
    char cur;
    unordered_set<char> hash;
    for (int r = 0; r < len; ++r) {
        for (int i = 0; i < n; ++i) {
            hash.insert(strs[i][r]);
            cur = strs[i][r];
        }
        if (hash.size() == 1) {
            ans += cur;
            hash.erase(cur);
        }
        else {
            break;
        }
    }
    return ans;
}

/* horizontal scanning: use string::find, string::substr and string::npos to find the prefix */
string longestPre(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }
    return prefix;
}

/* vertical */
string longestPre_ver(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    for (int i = 0; i < strs[0].length(); ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (i == strs[j].length() || strs[j][i] != strs[0][i]) { //the i-th character dose not match
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}


/* vertical & find the shortest first & fastest */
string longestCommonPrefix(vector<string>& strs) {
    string s; 
    char c;
    if  (strs.empty()) {
        return "";
    }
    
    int min = INT_MAX;
    for (auto s : strs) {    
        if (s.length() < min) {
            min = s.length();
        }
    }
    for (int i = 0; i < min; ++i) {             
        for (int j = 1; j < strs.size(); ++j) {        
            if (strs[j][i] != strs[0][i]) {
                return s;
            }
        }
        s.push_back(c);
    }
    return s;  
}