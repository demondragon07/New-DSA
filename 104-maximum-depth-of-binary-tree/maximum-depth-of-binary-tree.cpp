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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)return 0;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            level++;
            for(int i=0;i<sz;i++){
            auto u=q.front();
            q.pop();
            if(u->left!=NULL)
                q.push(u->left);
            if(u->right!=NULL)
                q.push(u->right);
            }
        }
        return level;
    }
};