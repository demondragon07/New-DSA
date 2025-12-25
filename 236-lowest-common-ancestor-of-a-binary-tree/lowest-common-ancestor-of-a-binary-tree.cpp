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
  bool solve(TreeNode*root,TreeNode*p,vector<TreeNode*>&ans){
    if(!root) return false;
    ans.push_back(root);
    if(root==p)return true;
    if(solve(root->left,p,ans) || solve(root->right,p,ans))return true;
    ans.pop_back();
    return false;
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1;
        vector<TreeNode*>ans2;
        bool a=solve(root,p,ans1);
        bool b=solve(root,q,ans2);
        TreeNode*ans=NULL;
        int sz1=ans1.size();
        int sz2=ans2.size();
        for(int i=0;i<sz1;i++){
            for(int j=0;j<sz2;j++){
                if(ans2[j]==ans1[i]){
                    ans=ans2[j];
                    break;
                }
            }
        }
        return ans;
    }
};