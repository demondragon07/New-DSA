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

  static bool cmp(ListNode*&a,ListNode*&b){
       return a->val<b->val;
     }

  ListNode* sortList(ListNode* head) {
        vector<ListNode*>v;
        ListNode*temp=head;
        if(head==NULL || head->next==NULL)return head;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->next;
        }
        sort(v.begin(),v.end(),cmp);
        temp=v[0];
        ListNode*temp1=temp;
        int n=v.size();
        int cnt=1;
        while(cnt<n){
            temp->next=v[cnt];
            cnt++;
            temp=temp->next;
        }
        temp->next=NULL;
        return temp1;
    }
};