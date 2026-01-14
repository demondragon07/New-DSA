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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*temp=new TreeNode(val);
        TreeNode*last=NULL;
        TreeNode*curr=root;
        if(!root)return temp;
        
        while(root){
            if(temp->val>root->val){
                last=root;
                root=root->right;
            }
            else {
                last=root;
                root=root->left;
            }
        } 
       if(last->val<val)last->right=temp;
       else last->left=temp;
     
     return curr;
    }
};