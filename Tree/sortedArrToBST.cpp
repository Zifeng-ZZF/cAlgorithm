#include <vector>
using namespace std;

/*
    convert a sorted array into a Binary Search Tree. Height difference should be no more than 1
    make use of DFS Inorder Traversal
    There is no unique solution
    sorted array actually represent the Inorder Traversal of BST
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

/* recursion */
/* calc the element at middle position, which also has middle value */
vector<int> arr;
TreeNode* helper(int left, int right) {
    if (left > right) {
        return NULL;
    }
    // Inorder Traversal
    TreeNode* root = new TreeNode;
    int mid = (left + right) / 2;
    root->left = helper(left, mid - 1);
    root->val = arr[mid];
    root->right = helper(mid + 1, right);
    return root;
}
TreeNode* toTree(vector<int>& nums) {
    arr = nums;
    return helper(0, arr.size() - 1);
}
