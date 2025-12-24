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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
           int sz=q.size();
           for(int i=0;i<sz;i++){
            auto u=q.front();
            q.pop();
            if(i==sz-1)ans.push_back(u->val);
            if(u->left!=NULL)q.push(u->left);
            if(u->right!=NULL)q.push(u->right);
           }
        }
      return ans;   
    }
};