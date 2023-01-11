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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return NULL;
        if(depth==1)
         {
             TreeNode *ele= new TreeNode(val);
             ele->left=root;
             return ele;
         }
        
          int count=1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            
             count++;
            if(count==depth)
                break;
            
            while(size--)
            {
                TreeNode *ele=q.front();
                q.pop();
                
                if(ele->left)
                q.push(ele->left);
                
                if(ele->right)
                q.push(ele->right);
                
            }
            
        }
        
       while(!q.empty())
       {
           TreeNode *ele=q.front();
           q.pop();
           TreeNode *ele1=ele->left;
           TreeNode *ele2=ele->right;
           
           ele->left=new TreeNode(val);
           
           ele->right=new TreeNode(val);
           
           ele->left->left=ele1;
           ele->right->right=ele2;
           
           
       }
        
       return root;
    }
};