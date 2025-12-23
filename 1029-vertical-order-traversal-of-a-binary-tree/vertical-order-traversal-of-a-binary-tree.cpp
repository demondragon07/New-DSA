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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        if(root==NULL)return {};
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            auto u=q.front();
            mp[u.second.first][u.second.second].insert(u.first->val);
            q.pop();
            if(u.first->left!=NULL){
                q.push({u.first->left,{u.second.first-1,u.second.second+1}});
            }
            if(u.first->right!=NULL){
                q.push({u.first->right,{u.second.first+1,u.second.second+1}});
            }
         }
        } 
        vector<vector<int>>ans;
        for(auto x:mp){
            vector<int>level;
          for(auto u:x.second){
            level.insert(level.end(),u.second.begin(),u.second.end());
          }
          ans.push_back(level);
        }
        return ans;
    }
};