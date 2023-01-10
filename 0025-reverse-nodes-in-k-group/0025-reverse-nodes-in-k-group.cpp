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
    int len(ListNode* head)
    {
        ListNode* current = head;
        int len = 0;
        while(current != NULL)
        {
            current = current -> next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head == NULL || len(head) < k) 
            return head;
      
      int count=0;
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next;
        
        while(curr!=NULL && count<k)
        {
            count++;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        if(next)
        {
            head->next=reverseKGroup(next,k);
        }
      
        return prev;
    }
};