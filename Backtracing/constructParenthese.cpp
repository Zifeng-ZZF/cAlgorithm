/* construct all possible combination of valid parenthese ()()() on given number of parenthese */
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/* backtracing using recursion and manipulation of parameter */
/* record the current number of left and right part */
void backtraceHelper(vector<string>& ans, string oneans, int left, int right, int n) {
    if (oneans.length() == 2 * n) {
        ans.push_back(oneans);
        return;
    }
    if (right > left) return;
    if (left < n) 
        backtraceHelper(ans, oneans + "(", left + 1, right, n); //backtrace by not actually manipulating the oneans but in the parameter
    if (right < n) 
        backtraceHelper(ans, oneans + ")", left, right + 1, n);//backtrace by not actually manipulating the oneans but in the parameter
}
vector<string> constructParenthese(int n) {
    vector<string> ans;
    backtraceHelper(ans, "", 0, 0, n);
    return ans;
}


/* additional related topic: validate parenthese []{}() */
bool validate(string str) {
    unordered_map<char, char> umap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    stack<char> st;
    //iterate the target string
    for (auto& ch : str) {
        // if left part, push into stack
        if (umap.find(ch) == umap.end()) {
            st.push(ch);
        }
        else {
            //if right part, test if it match the top
            if (st.empty() || st.top() != umap[ch]) 
                return false;
            //if matches, pop the matched left part
            st.pop();
        }
    }
    //at the end, if all matched, the stack will be empty
    return st.empty();
}