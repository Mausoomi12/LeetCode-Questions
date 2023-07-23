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
    unordered_map<int,vector<TreeNode*>>m;
    vector<TreeNode*> allPossibleFBT(int n) {
       vector<TreeNode*>ans;
       if(m.find(n)!=m.end()){
           return m[n];
       }
       if(n==1){
           TreeNode *temp = new TreeNode(0);
           ans.push_back(temp);
           return ans;
       }
       if(n%2){
           for(int i=0;i<n;i++){
               int left = i;
               int right = n - i - 1;
               vector<TreeNode*>l = allPossibleFBT(i);
               vector<TreeNode*>r = allPossibleFBT(right);
               for(auto x:l){
                   for(auto y:r){
                       TreeNode* temp = new TreeNode(0);
                       temp->left = x;
                       temp->right = y;
                       ans.push_back(temp);
                   }
               }
           }
           m[n] = ans;
       }      
       return ans;
    }
};