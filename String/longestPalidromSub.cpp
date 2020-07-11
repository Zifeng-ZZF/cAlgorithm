/* find the longest palidrom substring (not subsequence) */

#include <vector>
#include <string>
using namespace std;


/* using dynamic programming to find longest common substring of the original and the reverse string, dp to store current length */
/* need to exclude common substring in other part of string, so we need to check the original index of the substring */
/* i - 1 th elments match j - 1 th element: only valid if 

    (first element of the substr in the original str)                     (the original index for (j - 1)th element)
                            i - 1 - ([curlength] - 1)        ====         n - 1 - (j - 1)
                    then                 i - dp[i][j]        ====         n - j
*/
/* O(N^2) both time and space */
string reverse(string s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

string findLPS_one(string s) {
    if (s.empty()){
        return "";
    }
    string rev = reverse(s);
    int n = s.length();
    pair<int, int> maxval = {0, 0}; //start-point and size
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s[i - 1] == rev[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxval.second
                    && n - j == i - dp[i][j]) {
                    maxval.first = i - dp[i][j]; // = i - 1 - dp[i][j] + 1
                    maxval.second = dp[i][j]; // = size
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return s.substr(maxval.first, maxval.second);
}      


/* expand arond the center / dp/greedy */
/* 2n - 1 possible centers since a single char or between two chars can be the centers */
string findLPS_two(string s) {
    int n = s.length(), maxval = 0, start = 0;
    /* if the case is single element, exclude the first and the last one */
    for (int i = 1; i < n - 1; ++i) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (maxval < r - l) {
                maxval = r - l;
                start = l;
            }
            ++r;
            --l;
        }
    }

    /* if the case is between two elements */
    for (int i = 0; i < n - 1; ++i) {
        int l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (maxval < r - l) {
                maxval = r - l;
                start = l;
            }
            ++r;
            --l;
        }
    }
    return s.substr(start, maxval + 1);
}