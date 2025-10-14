class Solution {
public:
  void dfs(vector<bool>&vis,unordered_map<int,vector<int>>&adj, int u){
      if(vis[u]==true) return;
      vis[u]=true;
      for(auto v:adj[u]){
        if(!vis[v]) dfs(vis,adj,v);
      }
  }

int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1) adj[i].push_back(j);  
        }
    }
     int count=0;
      vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
           if(!vis[i]) {
            count++;
            dfs(vis,adj,i);
           }
        }
       return count; 
    }
};