/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void solve(TreeNode*root, string &ans){
        if(root==NULL){
            ans+="null,";
            return;
        }
      int k=root->val;
      ans+=to_string(k)+",";
      solve(root->left,ans);
      solve(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans;
        solve(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode*solve1(string &data,int &i){
        if(i>=data.size())return NULL;
           string rootval;
            while(data[i]!=','){
                rootval+=data[i];
                i++;
            }
            i++;
            if(rootval=="null") return NULL;
            int rootvall=stoi(rootval);
            TreeNode*root=new TreeNode(rootvall);
            root->left=solve1(data,i);
            root->right=solve1(data,i);
            return root;
    }
    TreeNode* deserialize(string data) {
        int i=0;
        return solve1(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));