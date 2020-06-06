#include <vector>
#include <string>
using namespace std;

int myAtoi(string str) {
    long ans = 0;
    int pre = 1;
    int len = str.length();
    //eliminate zero at the start
    str.erase(0, str.find_first_not_of(' '));
    for (int i = 0; i < len; ++i) {
        if (isdigit(str[i])) {
            ans = ans * 10 + (str[i] - '0');
            if (ans >= INT_MAX) {
                return INT_MAX;
            }
            if (ans <= INT_MIN) {
                return INT_MIN;
            }
        }
        else if (str[i] == '+' && i == 0) {
            pre = 1;
        }
        else if (str[i] == '-' && i == 0) {
            pre = -1;
        }
        else {
            return pre * ans;
        }
    }
    return pre * ans;
}