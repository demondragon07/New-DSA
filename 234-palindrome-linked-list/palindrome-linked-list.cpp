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
   ListNode* findmiddle(ListNode*head){
      ListNode*slow=head;
      ListNode*fast=head;
      while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
      }
      return slow;
   }

   ListNode*reverselist(ListNode*head){
       ListNode*curr=head;
       ListNode*prev=NULL;
       while(curr!=NULL){
        ListNode*forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
       }
     return prev;
   }
  
    bool isPalindrome(ListNode* head) {
       ListNode*middle=findmiddle(head);
       ListNode*second=reverselist(middle->next);
       ListNode*first=head;
       while(second!=NULL){
         if(first->val!=second->val) return false;
         first=first->next;
         second=second->next;
       }
     return true;
    }
};