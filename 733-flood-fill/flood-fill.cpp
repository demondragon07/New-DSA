class Solution {
public:
bool check(int i , int j ,int row ,int col){
    return ((i>-1 && i<row) && (j>-1 && j<col));
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        q.push({sr,sc});
        vis[sr][sc]=1;
        int oldcolor=image[sr][sc];
        image[sr][sc]=color;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        while(!q.empty()){
            auto x=q.front();
            int i=x.first;
            int j=x.second;
            q.pop();
            for(int k=0;k<4;k++){
                if(check(i+row[k],j+col[k],n,m) && !vis[i+row[k]][j+col[k]] && image[i+row[k]][j+col[k]]==oldcolor){
                    q.push({i+row[k],j+col[k]});
                    vis[i+row[k]][j+col[k]]=1;
                    image[i+row[k]][j+col[k]]=color;
                }
            } 
        }
        return image;
    }
};