class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        typedef pair<int,pair<int,int>> p;
        vector<vector<int>>directions={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        vector<vector<int>>result(n,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<n;
        };
        if(grid[0][0]!=0)return -1;
        pq.push({0,{0,0}});
        result[0][0]=0;
        while(!pq.empty()){
            auto p1=pq.top();
            int d=p1.first;
            int x=p1.second.first;
            int y=p1.second.second;
            pq.pop();
            for(auto dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(isSafe(x_,y_) && grid[x_][y_]==0 && d+1<result[x_][y_]){
                    result[x_][y_]=d+1;
                    pq.push({d+1,{x_,y_}});
                }
            }
        }
        if(result[n-1][n-1]==INT_MAX) return -1;
        return result[n-1][n-1]+1; 
    }
};