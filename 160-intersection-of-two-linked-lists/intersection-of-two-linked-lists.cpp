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
    int findlength(ListNode*head){
        ListNode*temp=head;
         int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode*skipnodes(ListNode*head, int len){
        ListNode*temp=head;
        while(len){
            len--;
           temp=temp->next;
        }
        return temp;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=findlength(headA);
        int n2=findlength(headB);
        ListNode*t1=NULL;
        ListNode*t2=NULL;
        if(n1>n2) {
            t1=skipnodes(headA,n1-n2);
            t2=headB;
        }
        else {
          t1=headA;
          t2=skipnodes(headB,n2-n1);
        }
         while(t1!=NULL && t2!=NULL){
            if(t1==t2) return t1;
             t1=t1->next;
             t2=t2->next;
         } 
       return NULL;

    }
};