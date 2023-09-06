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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;
        while(curr){
            n++;
            curr=curr->next;
        }
        
        vector<ListNode*> ans;
        int x=n/k;
        
        curr=head;
        for(int i=0;i<k;i++)
        {
            int realSize=x;
            if(i<n%k) realSize++;
            if(realSize==0)
            {
                ans.push_back(NULL);
                continue;
            }
            
            
            ans.push_back(curr);
            
            for(int j=0;j<realSize-1;j++)
            {
                curr=curr->next;
            }
            
            ListNode* temp=curr;
            curr=curr->next;
            temp->next=NULL;
        }
        
        
        return ans;
    }
};