/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
ListNode* swapPairs(ListNode* head)
{
   ListNode* curr= head;
   ListNode* prev = NULL;
   while(curr && curr->next != NULL)
   {  
       ListNode* currnext = curr->next;
       
       if(head == curr)
         head = currnext;
         
       curr->next = currnext->next;
       currnext->next = curr;
       if(prev)
         prev->next = currnext;
       
       prev = curr;
       curr = curr->next;
   }
   return head;        
}
};