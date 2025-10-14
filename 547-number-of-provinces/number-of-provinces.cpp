class Solution {
public:
  void dfs(vector<bool>&vis,vector<vector<int>>& isConnected, int u){
      if(vis[u]==true) return;
      vis[u]=true;
      for(int v=0;v<isConnected.size();v++){
        if(!vis[v] && isConnected[u][v]==1) dfs(vis,isConnected ,v); 
      }
  }    

int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
     int count=0;
      vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
           if(!vis[i]) {
            count++;
            dfs(vis,isConnected,i);
           }
        }
       return count; 
    }
};