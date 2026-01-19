/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
     void solve(TreeNode*root,TreeNode*p,vector<TreeNode*>&v1){
        v1.push_back(root);
        if(root==p) return;
        if(root->val<p->val)solve(root->right,p,v1);
        else solve(root->left,p,v1);
     }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           vector<TreeNode*>v1;
           vector<TreeNode*>v2;
            solve(root,p,v1);
            solve(root,q,v2);
            TreeNode*ans=NULL;
         for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i]==v2[i])ans=v1[i];
            else break;
         }
      return ans;
    }
};