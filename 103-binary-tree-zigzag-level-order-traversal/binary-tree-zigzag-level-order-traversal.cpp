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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        int flag=1;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int sz=q.size();
            for(int i=0;i<sz;i++){
              auto u=q.front();
              q.pop();
              level.push_back(u->val);
                   if(u->left!=NULL){
                    q.push(u->left);
                    }
                   if(u->right!=NULL){
                    q.push(u->right);
                   }
               
            }
            if(flag==0) {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            else ans.push_back(level);
             flag=1-flag;
        }
        return ans;
    }
};