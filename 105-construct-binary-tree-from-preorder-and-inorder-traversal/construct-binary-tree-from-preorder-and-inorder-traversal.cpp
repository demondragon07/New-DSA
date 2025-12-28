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
    TreeNode* solve(int instart, int inend, vector<int>&preorder, unordered_map<int,int>&mp, int &preidx){
        if(instart>inend)return NULL;
        int rootval=preorder[preidx];
        preidx++;
        TreeNode*root=new TreeNode(rootval);
        int mid=mp[rootval];
        root->left=solve(instart,mid-1,preorder,mp,preidx);
        root->right=solve(mid+1,inend,preorder,mp,preidx);
        return root;
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     int n=preorder.size();
     int preidx=0;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
     }
     return solve(0,n-1,preorder,mp,preidx);
    }
};