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
    bool helper(TreeNode* left,TreeNode* right){

        if(!left and !right)
            return true;
        if((left != NULL and right == NULL) || (left == NULL and right != NULL) || (left->val!=right->val))
            return false;
        if(left->val==right->val)
            return helper(left->right,right->left) && helper(left->left,right->right);
        return true;
    }

    bool isSymmetric(TreeNode* root) {

        if(!root)
            return true;
        return helper(root->left,root->right);
    }
};