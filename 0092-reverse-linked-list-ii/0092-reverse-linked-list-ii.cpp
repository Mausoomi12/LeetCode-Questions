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
    ListNode*rev(ListNode*head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)
            return head;
        if(left==right)
            return head;
        ListNode*curr=head;
        ListNode*t=NULL;
        ListNode*prev=NULL;
        ListNode*s=NULL;
        ListNode*v=NULL;
        bool f=0;
        if(left==1){
            f=1;
            t=curr;
        }
        int s1=1;
        while(curr!=NULL){
            if(s1==left&&f==0){
                v=prev;
                t=curr;
            }
            if(s1==right){
                s=curr->next;
                curr->next=NULL;
                break;
            }
            prev=curr;
            curr=curr->next;
            s1++;
        }
        if(f==0){
        v->next=NULL;
        }
        ListNode*ans=rev(t);
        t->next=s;
        if(f==0)
        v->next=ans;
        if(f==1)
            head=ans;
        return head;
    }
};