class Solution {
public:

 bool dfs(vector<vector<int>>&adj,int u,vector<int>&color,int currcol){
    color[u]=currcol;
    for(auto v:adj[u]){
        if(color[v]==color[u])return false;
        else if(color[v]==-1){
            color[v]=1-color[u];
            if(dfs(adj,v,color,color[v])==false) return false;
        }
    }
    return true;
 }
    bool isBipartite(vector<vector<int>>& graph) {
        //Red=1;
        //Green=0;
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1) {
                if(dfs(graph,i,color,1)==false)
                return false;
        }
      }
       return true;
    } 
};