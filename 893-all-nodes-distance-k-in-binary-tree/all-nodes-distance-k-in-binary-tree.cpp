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
  void markparent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp){
    if(!root)return;
    if(root->left)mp[root->left]=root;
    if(root->right)mp[root->right]=root;
    markparent(root->left,mp);
    markparent(root->right,mp);
  } 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return{};
        unordered_map<TreeNode*,TreeNode*>parent;
         markparent(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        int dist=0;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        while(!q.empty()){
            int sz=q.size();
            if(dist==k)break;
             dist++;
             for(int i=0;i<sz;i++){
                auto u=q.front();
                q.pop();
                if(u->left && !vis[u->left]){
                    q.push(u->left);
                    vis[u->left]=true;
                }
                if(u->right && !vis[u->right]){
                    q.push(u->right);
                    vis[u->right]=true;
                }
                if(parent[u] && !vis[parent[u]]){
                    q.push(parent[u]);
                    vis[parent[u]]=true;
                }
             }
        }
        vector<int>ans;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            ans.push_back(u->val);
        }
        return ans;
    }
};