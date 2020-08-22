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

/* Q : construct binary tree from preorder and inorder arrays */
/* preorder array is the order of root nodes from left to right */
int preIdx = 0;
TreeNode* helper(vector<int>& preorder, int left, int right, unordered_map<int, int>& umap);
TreeNode* constructOne(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if (n == 0) return NULL;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i) {
        umap[inorder[i]] = i;
    }
    return helper(preorder, 0, n - 1, umap);
}
TreeNode* helper(vector<int>& preorder, int left, int right, unordered_map<int, int>& umap) {
    if (left > right) return NULL;
    // use global variable to access next element in preorder array
    int val = preorder[preIdx++];
    // find the index of the current node in the inorder 
    int idx = umap[val];

    // create current nodes based on preorder element
    TreeNode* root = new TreeNode(val);
    // append from left subtree to right subtree
    // left subtree nodes are at the left to the current index in inorder array
    root->left = helper(preorder, 0, idx - 1, umap);
    // right subtree nodes are at the right to the current index in inorder array
    root->right = helper(preorder, idx + 1, right, umap);
    // finish appending, return
    return root;
}


/* Q : construct binary tree from postorder and inorder arrays */
/* postorder is the reverse of right-first preorder traversal */
/* same as preorder but need to reverse postorder and then construct right subtree first */
TreeNode* helper(vector<int>& preorder, int left, int right, unordered_map<int, int>& umap) {
    if (left > right) return NULL;
    int val = preorder[preIdx++];
    int idx = umap[val];
    TreeNode* root = new TreeNode(val);
    root->right = helper(preorder, idx + 1, right, umap); //right first
    root->left = helper(preorder, 0, idx - 1, umap);
    return root;
}