/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        if(curr == NULL || curr->next == NULL)
            return curr;
       ListNode* rest= curr->next;      
        ListNode* node =  reverseList(rest);
        
        rest->next = curr;
        curr->next = NULL;
        return node;
    }
    ListNode* NonRecReverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr= head;
        ListNode* after;
        
        while(curr != NULL)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;        
    }
};