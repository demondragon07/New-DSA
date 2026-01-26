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
   void solve(TreeNode*root ,vector<TreeNode*>&inorder){
    if(!root)return;
    solve(root->left,inorder);
    inorder.push_back(root);
    solve(root->right,inorder);
   }
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*>inorder;
        solve(root,inorder);
       int i=0;
       int n=inorder.size();
       int j=n-1;
       while(i<j){
           if(inorder[i]->val+inorder[j]->val==k) return true;
           else if(inorder[i]->val+inorder[j]->val>k) j--;
           else i++;
       }
       return false;
    }
};