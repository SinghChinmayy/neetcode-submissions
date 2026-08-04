/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
bool is_false = false; 
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int h_left = height(root->left);
        int h_right = height(root->right);
        bool l_bal = isBalanced(root->left);
        bool r_bal = isBalanced(root->right);
        if(abs(h_left - h_right) <= 1 && is_false == false) return true;
        else{
            is_false = true;
            return false;
        }
    }
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int h_left = height(root->left);
        int h_right = height(root->right);
        return h_left > h_right ? h_left + 1 : h_right + 1;
    }
};
