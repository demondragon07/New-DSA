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
    ListNode* deleteMiddle(ListNode* head) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int k=floor(len/2);
        int cnt=0;
        ListNode*prev=NULL;
        temp=head;
        if(head->next==NULL){
            head=head->next;
            return head;
        }
        while(cnt!=k){
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        if(cnt==k){
         prev->next=temp->next;
         delete(temp);
        }
        return head;
    }
};