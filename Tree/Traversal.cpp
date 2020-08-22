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
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
 

 #pragma region Inorder
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
        then make left as new current */
/* 本质是移动 */
vector<int> storeInorderWithMorris(TreeNode* root) {
    TreeNode* curr = root;
    vector<int> ans;
    while (curr != NULL) {
        /* reach the leftmost node and put it in answer; then move the cursor to the right*/
        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        /* has left node: then connect the left node's right tree to the head of its father's right tree */
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
    return ans;
}
#pragma endregion


#pragma region Pre-Order
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
#pragma endregion


#pragma region Post-Oreder
/* Q: hard question : postorder: left-right-root */
/* 1: recurssion method */
void printPostorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}
/* 2: iteration method with stack */
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
/* 3: iteration method wiht stack, reverse - preorder method, not visit postorder */
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
#pragma endregion


#pragma region Level-Order
/* Q: print node with BFS(level order tree traversal) */
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

/* Q: store each levels respectively */
/* 1: iteration solution with Queue */
vector<vector<int>> storeLevelOrderTraversal(TreeNode* root) {
    if (root == NULL) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> qu;
    qu.push(root); //make sure the top level is added beforehead 
    TreeNode* curr = NULL;
    int level = 0;
    while (!qu.empty()) {
        /* add a level to the answer */
        ans.push_back(vector<int>()); 
        /* n is the length of the current level */
        int n = qu.size();
        /* iterate through current level and pop current-level elements; And push next level's elements */
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

/* 2: recursion solution: actually DFS using mark of current level */
/* prototype */
void helper(TreeNode *, int, vector<vector<int>> &);
/* entry */
vector<vector<int>> storeLevelOrderTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    helper(root, 0, ans);
    return ans;
}
/* definition */
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
#pragma endregion


#pragma region ZigZag-Level-Order
/* Q: Binary Tree ZigZag Level Traversal */
/* 1: DFS recursion */
void helper(vector<vector<int>>&, int, TreeNode*);
vector<vector<int>> zigZagDFSwithMarking(TreeNode * root) {
    vector<vector<int>> ans;
    helper(ans, 0, root);
    return ans;
}
void helper(vector<vector<int>> & ans, int level, TreeNode * root) {
    if (root == nullptr) return;
    if (ans.size() == level) 
        ans.push_back(vector<int>());
    if (level % 2 == 0) 
        // insert from left to right at the end
        ans[level].push_back(root->val);
    else {
        // insert from left to right at the front
        auto it = ans[level].begin();
        ans[level].insert(it, root->val);
    }
    // iterate from left to right
    helper(ans, level + 1, root->left);
    helper(ans, level + 1, root->right);
}

/* 2: iteratore with two Stacks */
vector<vector<int>> zigZagLevelTraversal(TreeNode * root) {
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    stack<TreeNode*> oddst;
    stack<TreeNode*> evenst;
    evenst.push(root);

    int level = 0;
    TreeNode * temp;
    while (!oddst.empty() || !evenst.empty()) {
        int n = evenst.empty() ? oddst.size() : evenst.size();
        ans.push_back(vector<int>(n));
        if (level % 2 != 0) {
            for (int i = 0; i < n; ++i) {
                //current is odd
                temp = oddst.top();
                oddst.pop();
                ans[level][i] = temp->val;
                if (temp->right != nullptr) evenst.push(temp->right);
                if (temp->left != nullptr) evenst.push(temp->left);
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                //current is even
                temp = evenst.top();
                evenst.pop();
                ans[level][i] = temp->val;
                if (temp->left != nullptr) oddst.push(temp->left);
                if (temp->right != nullptr) oddst.push(temp->right);
            }
        }
        ++level;
    }
    return ans;
}

/* 3: double iteration with deque */
vector<vector<int>> zigZagDeque(TreeNode * root) {
    if (root == nullptr) return {};    
    vector<vector<int>> ans;
    deque<TreeNode*> dq;
    dq.push_back(root);
    
    int level = 0;
    TreeNode * temp;
    while (!dq.empty()) {
        int n = dq.size();
        ans.push_back(vector<int>(n));
        for (int i = 0; i < n; ++i) {
            if (level % 2 == 0) {
                temp = dq.front();
                dq.pop_front();
                ans[level][i] = temp->val;
                if (temp->left != nullptr) dq.push_back(temp->left);
                if (temp->right != nullptr) dq.push_back(temp->right);
            }
            else {
                temp = dq.back();
                dq.pop_back();
                ans[level][i] = temp->val;
                if (temp->right != nullptr) dq.push_front(temp->right);
                if (temp->left != nullptr) dq.push_front(temp->left);
            }
        }
        ++level;
    }
    return ans;
}

#pragma endregion


#pragma region Max-Depth
/* Q: Find the maximum depth of a given tree */
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
#pragma endregion