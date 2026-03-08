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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;

        ListNode*temp=head;
        if(temp==NULL)return NULL;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }

        int k=len-n+1;
        ListNode*prev=NULL;
        temp=head;
         if(k==1){
           head=head->next;
           return head;
         }
     
        int cnt=0;

        while(cnt!=k-1){
            cnt++;
            prev=temp;
            temp=temp->next;
        }

        if(cnt==k-1){
          prev->next=temp->next;
          delete(temp);
        }
        return head;
    }
};