class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
       vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
        queue<pair<int,int>>q;
        q.push({0,0});
        int level=0;
        if(grid[0][0]!=0) return -1;
        grid[0][0]=1;
        auto isSafe=[&](int x,int y){
           return x>=0 && x<n && y>=0 && y<n;
        };
        while(!q.empty()){
            int m=q.size();
            while(m--){
           pair<int,int>p=q.front();
           int x=p.first;
           int y=p.second;
           q.pop();
           if(x==n-1 && y==n-1)return level+1;
           for(auto dir:directions){
              int x_=x+dir[0];
              int y_=y+dir[1];
              if(isSafe(x_,y_) && grid[x_][y_]==0){
                q.push({x_,y_});
                grid[x_][y_]=1;
              }
           }
         }
         level++;
        } 
        return -1;
    }
};