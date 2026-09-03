class Solution {
public:
    bool check(int i , int j , int row ,int col){
        return ((i>-1 && i<row) && (j>-1 && j<col));
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int freshorange=0;
        int timer=0;
        queue<pair<pair<int,int>,int>>q;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)freshorange++;
            else if(grid[i][j]==2){
                q.push({{i,j},timer});
                grid[i][j]=0;
            }
        }
      }
      
      while(!q.empty()){
        int sz=q.size();
        timer=q.front().second;
        while(sz--){
        auto node=q.front();
        int i=node.first.first;
        int j=node.first.second;
        q.pop();
        for(int k=0;k<4;k++){
            if(check(i+row[k],j+col[k],n,m) && grid[i+row[k]][j+col[k]]==1)
            {
               freshorange--;
               q.push({{i+row[k],j+col[k]},timer+1});
               grid[i+row[k]][j+col[k]]=0;
            }
          } 
       }
    }
  if(freshorange)return -1;
  return timer;

    }
};