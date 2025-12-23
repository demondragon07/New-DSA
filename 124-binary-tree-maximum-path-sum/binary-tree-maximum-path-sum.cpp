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
    int solve(TreeNode*root,int &ans){
        if(root==NULL)return 0;
        int lans=solve(root->left,ans);
        int rans=solve(root->right,ans);
        ans=max({ans,lans+rans+root->val,max(lans,rans)+root->val,root->val});
        return max(max(lans,rans)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};