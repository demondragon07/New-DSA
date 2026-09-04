class Solution {
public:

    bool check(int i ,int j, int row , int col){
        return ((i>-1 && i<row) && (j>-1 && j<col));
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int dist=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},dist});
            }
        }

        while(!q.empty()){
            int sz=q.size();
            dist=q.front().second;
            while(sz--){
                auto x=q.front();
                int i=x.first.first;
                int j=x.first.second;
                q.pop();
                ans[i][j]=dist;
                for(int k=0;k<4;k++){
                    if(check(i+row[k],j+col[k],n,m) && mat[i+row[k]][j+col[k]]==1){
                        q.push({{i+row[k],j+col[k]},dist+1});
                        mat[i+row[k]][j+col[k]]=0;
                    }
                }
            }
        }
      return ans;
    }
};