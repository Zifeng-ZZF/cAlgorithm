#include <vector>
using namespace std;

/* Given coins of different denomiations and a total target amount, determine the minmum of coins needed to make up the amount */
/* return the fewest number of coins, otherwise return -1 */
/* This is a common backpack problem, or Change-Making problem: https://en.wikipedia.org/wiki/Change-making_problem */

/* 1.Backtracing Brute Force */
/* exponetial time 2^N, [TIME_LIMIT_EXCEEDED] */
int backtrace(vector<int>& coins, int amount, int idx);

int coin_backtrace(vector<int>& coins, int amount) {
    return backtrace(coins, amount, 0);
}

int backtrace(vector<int>& coins, int amount, int idx) {
    if (amount == 0) 
        return 0;
    if (idx == coins.size())
        return -1;
    
    int maxNumOfCoin = amount / coins[idx];
    int minCnt = INT_MAX;
    for (int i = 0; i <= maxNumOfCoin; ++i) {
        int otherCnt = backtrace(coins, amount - i * coins[idx], idx + 1);
        if (otherCnt != -1) {
            minCnt = min(minCnt, otherCnt + i);
        }
    }
    if (minCnt != INT_MAX)
        return minCnt;
    return -1;
}

/* 2.Dynamic Prgramming - Top-Down Solution */
/* use an extra memoization, take one coin at a time */
/* Time complexity: O(S * N), where S is the amount */
int backtrace_dp(vector<int>& coins, int amount, vector<int>& count);

int coin_dp_td(vector<int>& coins, int amount) {
    vector<int> count(amount);
    return backtrace_dp(coins, amount, count);
}

int backtrace_dp(vector<int>& coins, int amount, vector<int>& count) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    if (count[amount - 1] != 0) return count[amount - 1];

    int minCnt = INT_MAX;
    for (auto& coin : coins) {
        int res = backtrace_dp(coins, amount - coin, count);
        if (res != -1)
            minCnt = min(minCnt, res + 1);
    }
    count[amount - 1] = minCnt == INT_MAX ? -1 : minCnt;
    return count[amount - 1];
}

/* 3.Dynamic Programing - Bottom-Up Iteration Solution */
/* O(S * n) */
int coin_dp_bu(vector<int>& coins, int amount) {
    /* 不可以用INT_MAX，可能会造成溢出 */
    /* can't use more than 'amount' coins */
    int maxval = amount + 1;
    vector<int> dp(maxval, maxval);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        /* 对于当前给出的硬币，在当前的amount要的之前算出来的硬币数 */
        for (int& coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount] >= maxval ? -1 : dp[amount];
}



/* Variation: find the number of combinations from given set of denomiations that make up to the given amount */
/* Bottom-Up Dynamic Programming */
/*
    example: input{1, 2, 5}, target = 5
    for coin = 1:
        i = 1: coin <= i; dp[1] += dp[1-1] = 1
            2: coin <= i; dp[2] += dp[2-1] = 1
            3: coin <= i; dp[3] += dp[3-1] = 1
            4: coin <= i; dp[4] += dp[4-1] = 1
            5: coin <= i; dp[5] += dp[5-1] = 1
    for coin = 2:
        i = 1: coin > i
            2: coin <= i; dp[2] += dp[2-2] = 1 + 1 = 2
            3: coin <= i; dp[3] += dp[3-2] = 1 + 1 = 2
            4: coin <= i; dp[4] += dp[4-2] = 1 + 2 = 3
            5: coin <= i; dp[5] += dp[5-2] = 1 + 2 = 3
    for coin = 5:
        i = 1: coin > i
            2: coin > i
            3: coin > i
            4: coin > i
            5: coin <= i; dp[5] += dp[5-5] = 3 + 1 = 4
    return dp[5] = 4;
*/
int coinCountDP(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    /* 计算每种面值组成当前amount的形式的次数 */
    for (int& coin : coins) {
        for (int i = 1; i <= amount; ++i) {
            if (coin <= i) {
                /* dp[i - coin] contains previous denominations' result, and current denomination's result */
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[amount];
}