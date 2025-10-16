class Solution {
public:
 void DFS(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int &vertex,int &edges){
    if(vis[u]==true) return;
    vis[u]=true;
    vertex+=1;
    edges+=adj[u].size();
    for(auto v:adj[u]){
        if(!vis[v]) DFS(v,adj,vis,vertex,edges);
    }
 }
    int countCompleteComponents(int n, vector<vector<int>>& edges){
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
         if(vis[i]==false){
            int vertex=0;
            int edg=0;
            DFS(i,adj,vis,vertex,edg);
            if(((vertex*(vertex-1))/2==edg/2)) count++;
        }
     }
     return count;
    } 
};