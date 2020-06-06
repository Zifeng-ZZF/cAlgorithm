#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

/* recursion: passing bounds to subtree */
bool helper(TreeNode* root, long lower, long upper) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= lower || root->val >= upper) {
        return false;
    }
    if (!helper(root->right, root->val, upper) || !helper(root->left, lower, root->val)) {
        return false;
    }
    return true;
}

bool isValid_one(TreeNode* root) {
    return helper(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
}


/* DFS: Inorder using stack */
bool isValid_two(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    long lower = (long)INT_MIN - 1;
    vector<TreeNode *> stack;
    while (root != NULL || !stack.empty()) {
        while (root != NULL) {
            stack.push_back(root);
            root = root->left;
        }
        root = stack.back();
        stack.pop_back();
        if (root->val <= lower) {
            return false;
        }
        lower = root->val;
        root = root->right;
    }
    return true; 
}