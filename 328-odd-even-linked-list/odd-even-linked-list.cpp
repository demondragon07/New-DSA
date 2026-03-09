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
    ListNode*oddlength(ListNode*head){
        ListNode*curr=head;
        if(curr==NULL || curr->next==NULL)return curr;
        ListNode*prev=curr->next;
        while(curr->next!=NULL){
            ListNode*forward=curr->next;
            curr->next=forward->next;
            curr=forward;
        }
        curr->next=prev;
        return head;
    }

    ListNode*evenlength(ListNode*head){
        ListNode*curr=head;
        if(curr==NULL || curr->next==NULL)return curr;
        ListNode*prev=curr->next;
        while(curr->next->next!=NULL){
            ListNode*forward=curr->next;
            curr->next=forward->next;
            curr=forward;
        }
        curr->next=prev;
        return head;
    }

    ListNode* oddEvenList(ListNode* head) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
     if(len%2==0) return evenlength(head);
     return oddlength(head);
    }
};