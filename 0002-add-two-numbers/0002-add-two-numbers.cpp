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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize a dummy head node for the result linked list
        ListNode* result = new ListNode();
        ListNode* current = result;
        int carry = 0;

        // Loop through both linked lists until we reach the end of both
        while (l1 || l2) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // If there is a carry left over, create a new node with the carry value
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        // Return the result linked list, starting from the second node (first node is dummy)
        return result->next;
    }
};
