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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)
        return 0;

        int m=INT_MIN,level=0,max_level=-1;
        q.push(root);
        while(!q.empty()){
            level++;
            int s=q.size();
            int cs=0;
            while(s--){
                TreeNode* curr=q.front();
                q.pop();

                cs+=curr->val;
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);

            }
            if(m<cs){
            max_level=level;
            m=cs;
            }
        }
        return max_level;
    }
};