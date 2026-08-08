/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base condition
        // root is null -> full iteration done and subRoot not found
        if(root == nullptr) return false;

        // 1. check current node
        // 2.a. current node matches
        // -> do full subtree match
        if(root->val == subRoot->val) {
            // full subtree matching
            bool isMatch = treeMatch(root, subRoot);
            if(isMatch) return true;
        }

        // 2.b. current node does not give a match
        // -> move to next element of tree
        bool l_check = isSubtree(root->left, subRoot);
        bool r_check = isSubtree(root->right, subRoot);

        if(l_check || r_check) return true;

        return false;
    }

    bool treeMatch(TreeNode* root, TreeNode* subRoot) {
        // base case
        // both tree and subtree terminate completely
        if(root == nullptr && subRoot == nullptr) return true;

        // one ends and other does not -> one tree is incomplete
        if(root == nullptr || subRoot == nullptr) return false;

        // nodes match -> recursively check children
        if(root->val == subRoot->val) {
            bool l_check = treeMatch(root->left, subRoot->left);
            bool r_check = treeMatch(root->right, subRoot->right);

            if(l_check && r_check) return true;
        }

        return false;
    }
};