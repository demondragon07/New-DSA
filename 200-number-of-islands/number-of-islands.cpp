class Solution {
public:
 bool check(int i , int j , int row , int col){
      return ((i>-1 && i<row) && (j>-1 &&j<col));
  }
  void BFS(int i,int j,vector<vector<char>>& grid){
          int n=grid.size();
          int m=grid[0].size();
          int row[8]={-1,1,0,0};
          int col[8]={0,0,1,-1};
          queue<pair<int,int>>q;
          q.push({i,j});
          grid[i][j]='0';
          while(!q.empty()){
              auto x=q.front();
              int i=x.first;
              int j=x.second;
              q.pop();
              for(int k=0;k<8;k++){
                  if(check(i+row[k],j+col[k],n,m) && grid[i+row[k]][j+col[k]]=='1'){
                      q.push({i+row[k],j+col[k]});
                      grid[i+row[k]][j+col[k]]='0';
                  }
              }
          }
  }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    BFS(i,j,grid);
                }
            }
        }
        return count;
    }
};