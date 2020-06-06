#include <vector>
using namespace std;

/* iteration O(n) time O(1) space; but recursion take O(n) space because of call stack */
void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
    }
}

/* may out of range, so use long to test range */
int reverseInteger(int x) {
    long ans = 0;
    while (x != 0) {
        if (ans * 10 > INT_MAX || ans * 10 < INT_MIN) {
            return 0;
        }
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}