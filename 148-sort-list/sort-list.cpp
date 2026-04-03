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
  ListNode*findmiddle(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
  }
   
   ListNode*mergetwosortedlists(ListNode*L1,ListNode*L2){
     if(L1==NULL) return L2;
     if(L2==NULL) return L1;
     ListNode*result=NULL;
     if(L1->val<=L2->val){
        result=L1;
        result->next=mergetwosortedlists(L1->next,L2);
     }else{
        result=L2;
        result->next=mergetwosortedlists(L1,L2->next);
     }
     return result;
   }
  
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
         ListNode*middle=findmiddle(head);
         ListNode*right=middle->next;
         middle->next=NULL;
         ListNode*left=head;
         ListNode*L1=sortList(left);
         ListNode*L2=sortList(right);
         return mergetwosortedlists(L1,L2);
    }
};