/*
    Depth First Search (DFS):
        * inorder: left, root, right
            - In case of Binary Search Tree(BST), it provides non-decreasing order
        * preorder: root, left, right
            - Create copy of the tree
            - Get prefix expression of an expression tree
        * posterorder: left, right, root
            - Is used to delete the tree
            - Get postfix expression of an expression tree
    Breath First Search (BFS): level order tree traversal
*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
 
/*
    print node with different order in DFS
*/
void printInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
/* inorder without recursion */
void printInorderWithStack(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    vector<TreeNode *> stack;
    TreeNode* cur = root;
    while (cur != NULL || !stack.empty()) {
        while (cur != NULL) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        cout << cur->val << " "; //printing/or other operations
        cur = cur->right;
    }
}

void printPreorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}


/*
    print node with BFS(level order tree traversal)
*/
void printBFS(TreeNode* root) {
    if (root == NULL) {
        cout << "NULL!" << endl;
    }
    queue<TreeNode *> qu;
    qu.push(root);
    TreeNode* node = NULL;
    while (!qu.empty()) {
        node = qu.front();
        qu.pop();
        cout << node->val << endl;
        qu.push(node->left);
        qu.push(node->right);
    }
}

/*
    Find the maximum depth of a given tree 
*/
/* recursion: DFS */
int findMaxDepth_one(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(1 + findMaxDepth_one(root->left), 1 + findMaxDepth_one(root->right));
}

/* iteration: make use of stack(for DFS), record every nodes height */
int findMaxDepth_two(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    vector<pair<int, TreeNode*>> stack;
    int maxD = 1;
    stack.push_back(pair<int, TreeNode*>(maxD, root));
    while (!stack.empty()) {
        pair<int, TreeNode*> p = stack.back();
        int depth = get<0>(p);
        TreeNode* node = get<1>(p);
        maxD = max(depth, maxD);
        stack.pop_back();
        if (node->right != NULL) {
            stack.push_back(pair<int, TreeNode*>(depth + 1, node->right));
        }
        if (node->left != NULL) {
            stack.push_back(pair<int, TreeNode*>(depth + 1, node->left));
        }
    }
    return maxD;
}