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
    int findlength(ListNode*head){
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode*findkthnode(ListNode*head, int k){
        ListNode*temp=head;
        while(k){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode*findlastnode(ListNode*head){
      ListNode*temp=head;
      ListNode*prev=head;
      while(temp!=NULL){
        prev=temp;
        temp=temp->next;
      }
      return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len=findlength(head);
        if(head==NULL || head->next==NULL || k==0 )return head;
        k=k%len;
        if(k==0)return head;
        ListNode*kthnode=findkthnode(head,len-k-1);
        ListNode*nextnode=kthnode->next;
        kthnode->next=NULL;
        ListNode*lastnode=findlastnode(nextnode);
        lastnode->next=head;
        return nextnode;
    }
};