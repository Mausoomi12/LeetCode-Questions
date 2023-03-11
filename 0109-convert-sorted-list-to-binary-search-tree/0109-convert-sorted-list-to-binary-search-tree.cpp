/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* chk(int i, int j, vector<int>& v){

        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=chk(i, mid-1, v);
        root->right=chk(mid+1, j, v);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int i=0, j=v.size();
        return chk(i, j-1, v);
    }
};