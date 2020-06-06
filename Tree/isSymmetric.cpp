/*
    determine a tree is symmetric or not
*/

#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

/* recursion: dfs, to compare right tree with left tree, right nodes with right nodes */
bool helper(TreeNode* l, TreeNode* r) {
    if (l == r) {
        return true;
    }
    if (l == NULL || r == NULL) {
        return false;
    }
    if (l->val == r->val) {
        return helper(l->right, r->left) && helper(l->left, r->right);
    }
}
bool isSymmetric_one(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return helper(root->left, root->right);
}

/* iteration: bfs, push left and right sub-tree of the root to two queues, with different order of push left, right nodes */
bool isSymmetric_two(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty()) {
        TreeNode* left = q1.front();
        q1.pop();
        TreeNode* right = q2.front();
        q2.pop();

        if (left == right) { // left == right == NULL
            continue;
        }

        if ((left == NULL && right != NULL)
            || (left != NULL && right == NULL)
            || (left->val != right->val)) {
                return false;
        }

        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
    return true;
}