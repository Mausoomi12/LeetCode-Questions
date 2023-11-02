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
    vector<int> postorder(TreeNode* root)
    {
        if(root == NULL)
            return {0, 0, 0};
        auto left = postorder(root->left);
        auto right = postorder(root->right);
        int sum = left[0] + right[0] + root->val;
        int count = 1 + left[1] + right[1];
        int res = left[2] + right[2] + (sum/count == root->val);
        return {sum, count, res};
    }
    int averageOfSubtree(TreeNode* root) {
        return postorder(root)[2];
    }
};