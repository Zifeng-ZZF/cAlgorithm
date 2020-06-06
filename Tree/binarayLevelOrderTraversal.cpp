/*
    put every level into an array, return all the levels
*/
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

/* recursion: mark order of level */
vector<vector<int>> ans;
void helper(TreeNode* root, int level) {
    if (ans.size() == level) {
        ans.push_back(vector<int>());
    }
    ans[level].push_back(root->val);
    if (root->left != NULL) {
        helper(root->left, level + 1);
    }
    if (root->right != NULL) {
        helper(root->right, level + 1);
    }
}
vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return {};
    }
    helper(root, 0);
    return ans;
}

/* iteration: bfs using queue */
vector<vector<int>> traversal_two(TreeNode* root) {
    if (root == NULL) {
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    int len = 0, level = 0;
    TreeNode* node;
    while (!q.empty()) {
        len = q.size();
        ans.push_back(vector<int>());
        for (int i = 0; i < len; ++i) {
            node = q.front();
            q.pop();
            ans[level].push_back(node->val);
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        ++level;
    }
    return ans;
}