class Solution {
public:
    bool check(int i , int j ,int row ,int col){
        return ((i>-1 && i<row) && (j>-1 && j<col));
    }
    void BFS(int i , int j ,vector<vector<int>>& grid ,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        while(!q.empty()){
            auto x=q.front();
            int i=x.first;
            int j=x.second;
            q.pop();
        for(int k=0;k<4;k++){
            if(check(i+row[k],j+col[k],n,m) && grid[i+row[k]][j+col[k]]==1  && !vis[i+row[k]][j+col[k]]){
                vis[i+row[k]][j+col[k]]=1;
                q.push({i+row[k],j+col[k]});
            }
          }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    vis[i][j]=1;
                    BFS(i,j,grid,vis);
                }
            }
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) cnt++;
            }
     return cnt;   
     
    }
};