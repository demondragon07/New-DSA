class Solution {
public:
bool check(int i ,int j, int row , int col){
    return (i>-1 && i<row) && (j>-1 && j<col); 
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O') {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }

        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        while(!q.empty()){
            auto x=q.front();
            int i=x.first;
            int j=x.second;
            q.pop();
            for(int k=0;k<4;k++){
                if(check(i+row[k],j+col[k],n,m) && board[i+row[k]][j+col[k]]=='O' 
                 && !vis[i+row[k]][j+col[k]]){
                    q.push({i+row[k],j+col[k]});
                    vis[i+row[k]][j+col[k]]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')board[i][j]='X';
            }
    }
};