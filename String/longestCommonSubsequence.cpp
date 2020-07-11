#include <string>
#include <vector>
using namespace std;

/*
    Find the longest common subsequence for two strings
    It is not consecutive
    Method: Dynamic Programming
    1. memoization
    2. tabulation
    3. dynamic programming
*/

/* 1. memoization: top-down recursion solution */
/* there are two cases: two letters match / don't match
/* base cases: from left to right if no match return 0 */
vector<vector<int>> memo;
string str1, str2;

int helper(int i, int j) {
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    int ans;
    if (str1[i] == str2[j]) {
        ans = helper(i + 1, j + 1) + 1;
    }
    else {
        ans = max(helper(i + 1, j), helper(i, j + 1));
    }
    memo[i][j] = ans;
    return ans;
}

int findLCS(string s1, string s2) {
    memo = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 0; i < s1.length(); ++i) {
        for (int j = 0; j < s2.length(); ++j) {
            memo[i][j] = -1;
        }
    }
    str1 = s1;
    str2 = s2;
    return helper(0, 0);
}


/* 2. bottom-up dynamic programming */
/* case1: if matched, then both move forward and plus on */
/* case2: if not match, then move either of the two forward and find the max */
int findLCS_2(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

