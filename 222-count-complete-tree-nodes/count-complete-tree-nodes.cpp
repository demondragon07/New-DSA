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
    int lefth(TreeNode*root){
        if(!root)return 0;
        int hg=0;
        while(root){
            root=root->left;
            hg++;
        }
        return hg;
    }

    int righth(TreeNode*root){
        if(!root) return 0;
        int hg=0;
        while(root){
            hg++;
            root=root->right;
        }
     return hg;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftheight=lefth(root);
        int rightheight=righth(root);
        if(leftheight==rightheight) return (1<<leftheight)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};