#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int val) : val(val) {}
};

/* construct binary tree from preorder and inorder arrays */
int preIdx = 0;
TreeNode* helper(vector<int>& preorder, int left, int right, unordered_map<int, int>& umap) {
    if (left > right) return NULL;
    int val = preorder[preIdx++];
    int idx = umap[val];
    TreeNode* root = new TreeNode(val);
    root->left = helper(preorder, 0, idx - 1, umap);
    root->right = helper(preorder, idx + 1, right, umap);
    return root;
}
TreeNode* constructOne(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if (n == 0) return NULL;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i) {
        umap[inorder[i]] = i;
    }
    return helper(preorder, 0, n - 1, umap);
}


/* construct binary tree from postorder and inorder arrays */
/* postorder is the reverse of right-first preorder traversal */
/*
    same as preorder but need to construct right subtree first
*/
TreeNode* helper(vector<int>& preorder, int left, int right, unordered_map<int, int>& umap) {
    if (left > right) return NULL;
    int val = preorder[preIdx++];
    int idx = umap[val];
    TreeNode* root = new TreeNode(val);
    root->right = helper(preorder, idx + 1, right, umap); //right first
    root->left = helper(preorder, 0, idx - 1, umap);
    return root;
}