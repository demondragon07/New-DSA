class Solution {
public:
   void BFS(vector<bool>&vis, vector<vector<int>>&isConnected,queue<int>&q){
          while(!q.empty()){
             int u=q.front();
              vis[u]=true;
              q.pop();
              for(int v=0;v<isConnected.size();v++){
                if(!vis[v] && isConnected[u][v]==1)
                { 
                    q.push(v);
                }    
              }
          }
          
   }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        queue<int>q;
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                 q.push(i);
                BFS(vis,isConnected,q);            
                }
           }
          return count; 
      }
};