class Solution {
public:

    void DFS(int node,vector<vector<int>>&isConnected,vector<int>&vis){
        if(vis[node])return;
        vis[node]=1;
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i])DFS(i,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                DFS(i,isConnected,vis);
            }
        }
        return ans;
    }
};