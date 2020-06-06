#include <string>
using namespace std;

string countAndSay_one(int n) {
    if (n <= 1) {
        return "1";
    }
    if (n == 2) {
        return "11";
    }
    string ans;
    string prev = "11";
    int count = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j < prev.length(); ++j) {
            if (prev[j] == prev[j - 1]) {
                ++count;
            }
            else {
                ans = ans + (char)(count + '0') + prev[j - 1];
                count = 1;
            }
        }
        ans = ans + (char)(count + '0') + prev[prev.length() - 1];
        prev = ans;
        ans = "";
        count = 1;
    }
    return prev;
}

/* recursion */
string countAndSay_two(int n) {
    if (n <= 1) {
        return "1";
    }
    if (n == 2) {
        return "11";
    }
    string prev = countAndSay_two(--n);
    int count = 1;
    string ans;
    for (int i = 1; i < prev.length(); ++i) {
        if (prev[i] == prev[i - 1]) {
            ++count;
        }
        else {
            ans = ans + (char)(count + '0') + prev[i - 1];
            count = 1;
        }
    }
    ans = ans + (char)(count + '0') + prev[prev.length() - 1];
    return ans;
}