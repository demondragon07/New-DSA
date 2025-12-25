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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long sz=q.size();
            long long first=0; 
            long long last=0;
            long long mini=INT_MAX;
            for(int i=0;i<sz;i++){
                auto u=q.front();
                q.pop();
                if(i==0)mini=u.second;
                long long curridx=u.second-mini;
                if(u.first->left) q.push({u.first->left,(1LL)*2*curridx+1});
                if(u.first->right) q.push({u.first->right,(1LL)*2*curridx+2});
                if(i==0)first=curridx;
                if(i==sz-1)last=curridx;
                ans=max(ans,last-first+1);
            }
        }
     return (int)ans; 
    }
};