class Solution {
public:
int m , n;
    vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>&board ,string &word ,int idx ,int i , int j){
        if(idx==word.size())return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false;
        if(board[i][j]!=word[idx]) return false;
        char temp=board[i][j];
        board[i][j]='$';
        for(auto &x:directions){
          int new_i=i+x[0];
          int new_j=j+x[1];
          if(find(board,word,idx+1,new_i,new_j)) return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m=board.size();
         n=board[0].size();
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board,word,0,i ,j)) return true;
            }
         }
         return false;
    }
};