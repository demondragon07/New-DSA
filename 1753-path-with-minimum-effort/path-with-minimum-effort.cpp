class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        typedef pair<int,pair<int,int>> p;
        vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<p,vector<p>,greater<p>>pq;
        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        pq.push({0,{0,0}});
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        result[0][0]=0;
        while(!pq.empty()){
            auto p1=pq.top();
            int diff=p1.first;
            int x=p1.second.first;
            int y=p1.second.second;
            pq.pop();
            for(auto dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(isSafe(x_,y_)){
                    int absdiff=abs(heights[x_][y_]-heights[x][y]);
                    int maxdiff=max(absdiff,diff);
                    if(maxdiff<result[x_][y_]){
                        result[x_][y_]=maxdiff;
                        pq.push({maxdiff,{x_,y_}});
                    }
                }
            }
        } 
       return  result[n-1][m-1];
    }
};