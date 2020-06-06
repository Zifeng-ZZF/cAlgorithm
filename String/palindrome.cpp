#include <vector>
#include <string>
using namespace std;

/* isalnum: check if a character is alphanumeric (letter or number) */
/* tow pointers solution */
/* faster solution */
bool isPalindrome_one(string s) {
    for (int l = 0, r = s.length() - 1; l <= r; ++l, --r) {
        while (l <= r && !isalnum(s[l])) {
            ++l;
        }
        while (l <= r && !isalnum(s[r])) {
            --r;
        }
        if (l > r) {
            break;
        }
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
    }
    return true;
}

/* reverse string solution */
bool isPalindrome_two(string s) {
    string reverse;
    string alphanumeric;
    for (auto& c : s) {
        if (isalnum(c)) {
            alphanumeric += tolower(c);
        }
    }
    string::reverse_iterator it = alphanumeric.rbegin();
    string::reverse_iterator ie = alphanumeric.rend();
    while (it != ie) {
        reverse += *it;
        ++it;
    }
    return reverse == alphanumeric;
}