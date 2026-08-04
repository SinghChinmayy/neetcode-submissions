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
    int diameterOfBinaryTree(TreeNode* root) {
        // base termination case
        if(root == nullptr) return 0;
        // computing height
        int h_left = height(root->left);
        int h_right = height(root->right);
        int diameter = h_left + h_right;
        int r_dia =  diameterOfBinaryTree(root-> right);
        int l_dia =  diameterOfBinaryTree(root-> left);
        return (r_dia > l_dia && r_dia > diameter)? r_dia : (diameter > l_dia ? diameter : l_dia);
    }
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int h_left = height(root->left);
        int h_right = height(root->right);
        return h_left > h_right ? h_left + 1: h_right + 1;
    }
};
