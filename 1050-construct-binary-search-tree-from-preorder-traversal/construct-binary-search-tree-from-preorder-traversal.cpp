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
    void solve(TreeNode*root,vector<int>preorder, int idx ,int n){
      if(idx>=n)return;
      TreeNode*temp=root;
      while(root!=NULL){
        if(root->val>preorder[idx] && root->left!=NULL)root=root->left;
        else if(root->val<preorder[idx] && root->right!=NULL)root=root->right;
        else break;
      }
      if(root->val>preorder[idx])root->left=new TreeNode(preorder[idx]);
      else root->right=new TreeNode(preorder[idx]);
      root=temp;
      solve(root,preorder,idx+1,n);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=new TreeNode(preorder[0]);
       solve(root,preorder,1, preorder.size());
       return root;
    }
};