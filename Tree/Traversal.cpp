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
#include <stack>
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
/* inorder with Morris method, without stack & recursion */
/* if has no left nodes, print it. and move right-wards
    if has left nodes, move current to the rightest of its left subtress.
        then make left as new current
*/
/* 本质是移动 */
void printInorderWithMorris(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->val;
            curr = curr->right;
        }
        else {
            TreeNode* rightmost = curr->left;
            TreeNode* temp = curr->left;
            while (rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            rightmost->right = curr;
            curr->left = NULL; //cut lose original link
            curr = temp;
        }
    }
}


/* preorder root-left-right */
/* preorder traversal with recurssion */
void printPreorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
/* preorder with stack, iteration */
void printPreorderStack(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode *curr = NULL;
    while (!st.empty()) {
        curr = st.top();
        st.pop();
        cout << curr->val;
        if (curr->right != NULL) st.push(curr->right); //right first-in last-out
        if (curr->left != NULL) st.push(curr->left);
    }
}
/* preorder with Morris */
/* form a circle when first reach right-est leave of left subtree */
/* 本质是形成环 */
void printPreorderWithMorris(TreeNode* root) {
    if (root == NULL) return;
    TreeNode *curr = root;
    while (curr != NULL) {
        //see if curr has left sub-tree
        if (curr->left == NULL) {
            //if not, store val and move right-wards
            cout << curr->val;
            curr = curr->right;
        }
        else {
            //if yes, find the right-es leaves of its left subtree
            TreeNode* pre = curr->left;
            //or find a cycle
            while (pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }
            //if find the right-est leaves, since it's pre-order, we store the curr val first, then form a cycle by linking curr to the left sub-tree
            if (pre->right == NULL) {
                cout << curr->val;
                pre->right = curr;
                curr = curr->left;
            }
            //when left subtree is done iterated, curr goes back to the root, pre then follows the cycle to point back to root
            else {
                //left subtree is done, go to right node
                curr = curr->right;
                //cut the link
                pre->right = NULL;
            }
        }
    }
}


/* hard question : postorder: left-right-root */
/* recurssion method */
void printPostorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}
/* iteration method with stack */
void printPostorderWithStack(TreeNode* root) {
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while (!st.empty() || curr != NULL) {
        //reach the left-est leaves of each nodes
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        TreeNode* temp = st.top();
        if (temp->right == NULL) {
            st.pop(); //pop if it is a leaf
            cout << temp->val;
            while (!st.empty() && temp == st.top()->right) {
                temp = st.top();
                st.pop(); //pop if both left and right are printed
                cout << temp->val;
            }
        }
        else {
            curr = temp->right;
        }
    }
}
/* iteration method wiht stack, reverse - preorder method, not visit postorder */
/* root - right - left and then reverse */
vector<int> printPostorderStackReverse(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    TreeNode* curr = NULL;
    stack<TreeNode*> st;
    deque<int> ans;
    vector<int> res;
    st.push(root);
    while (!st.empty()) {
        curr = st.top();
        ans.push_front(curr->val);
        st.pop();
        if (curr->left != NULL) st.push(curr->left);
        if (curr->right != NULL) st.push(curr->right);
    }
    for (auto& a : ans) {
        res.push_back(a);
    }
    return res;
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
/* store each levels respectively */
/* iteration solution with Queue */
vector<vector<int>> storeLevelOrderTraversal(TreeNode* root) {
    if (root == NULL) return {};
    vector<vector<int>> ans;
    int level = 0;
    queue<TreeNode*> qu;
    qu.push(root);
    TreeNode* curr = NULL;
    while (!qu.empty()) {
        ans.push_back(vector<int>());
        int n = qu.size();
        for (int i = 0; i < n; ++i) {
            curr = qu.front();
            qu.pop();
            ans[level].push_back(curr->val);
            if (curr->left != NULL) qu.push(curr->left);
            if (curr->right != NULL) qu.push(curr->right);
        }
        ++level;
    }
    return ans;
}
/* recursion solution: actually DFS using mark of current level */
void helper(TreeNode* root, int level, vector<vector<int>>& ans) {
    if (ans.size() == level) {
        ans.push_back(vector<int>());
    }
    ans[level].push_back(root->val);
    if (root->left != NULL) 
        helper(root->left, level + 1, ans);
    if (root->right != NULL)
        helper(root->right, level + 1, ans);      
}
vector<vector<int>> storeLevelOrderTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    helper(root, 0, ans);
    return ans;
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