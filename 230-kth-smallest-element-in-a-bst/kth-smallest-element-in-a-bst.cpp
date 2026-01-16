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
   void solve(TreeNode*root, vector<TreeNode*>&v){
    if(!root)return;
    solve(root->left,v);
    v.push_back(root);
    solve(root->right,v);
   }

    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*>v;
       solve(root,v); 
       int idx=k-1;
       return v[idx]->val;
    }
};