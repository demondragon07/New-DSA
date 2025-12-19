/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //using 2 stack
        vector<int>ans;
        if(root==NULL){
          return {};
        }
     stack<TreeNode*>st1;
     stack<TreeNode*>st2;
    st1.push(root);
    while(!st1.empty()){
       auto u=st1.top();
       st2.push(u);
       st1.pop();
       if(u->left!=NULL){
        st1.push(u->left);
       }
       if(u->right!=NULL){
        st1.push(u->right);
       } 
    }
     
   while(!st2.empty()){
    auto u=st2.top();
    st2.pop();
    ans.push_back(u->val);
   }  

 return ans;
    }
};