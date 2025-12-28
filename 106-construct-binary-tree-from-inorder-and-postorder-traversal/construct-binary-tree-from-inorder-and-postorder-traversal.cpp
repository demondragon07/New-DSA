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
   TreeNode*solve(int instart,int inend,vector<int>&postorder,int &postidx,unordered_map<int,int>&mp){
     if(instart>inend)return NULL;
     int rootval=postorder[postidx];
     postidx--;
     TreeNode*root=new TreeNode(rootval);
     int mid=mp[rootval]; 
     root->right=solve(mid+1,inend,postorder,postidx,mp);
     root->left=solve(instart,mid-1,postorder,postidx,mp);
     return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int postidx=n-1;
       return solve(0,n-1,postorder,postidx,mp);
    }
};