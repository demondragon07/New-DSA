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
  void solve(TreeNode*root ,vector<pair<int,pair<int,int>>>&p){
       auto u=p.back(); 
       if(root==NULL)return;    
       if(root->left!=NULL){
         p.push_back({root->left->val,{u.second.first+1,u.second.second-1}});
         solve(root->left,p);
       }
       if(root->right!=NULL){
        p.push_back({root->right->val,{u.second.first+1,u.second.second+1}});
        solve(root->right,p);
       }
   }
   static bool comp(pair<int,pair<int,int>>&a ,pair<int,pair<int,int>>&b){
        if(a.second.second==b.second.second && (a.second.first==b.second.first)) return a.first<b.first;
        else if(a.second.second==b.second.second && (a.second.first!=b.second.first)) return a.second.first<b.second.first;
        else return a.second<b.second;
   }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>>p;
        if(root==NULL)return {};
        p.push_back({root->val,{0,0}});
        solve(root,p);
        sort(p.begin(),p.end(),comp);
        int minidx=INT_MAX;
        int maxidx=INT_MIN;
        for(auto x:p){
            minidx=min(minidx,x.second.second);
            maxidx=max(maxidx,x.second.second);
        }
       int sz=maxidx-minidx+1;
       vector<vector<int>>ans(sz);
       for(auto x:p){
        int val=x.first;
        int oldidx=x.second.second;
        int shidx=oldidx-minidx;
        ans[shidx].push_back(val);
       }

       return ans;
    }
};