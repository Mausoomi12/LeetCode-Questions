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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>list;
        while(head!=NULL){
            list.push_back(head->val);
            head=head->next;
        }
        int n=list.size();
        int mxSum=0;
        for(int i=0;i<n/2;i++){
            mxSum=max(mxSum,list[i]+list[n-1-i]);
        }
        return mxSum;
    }
};