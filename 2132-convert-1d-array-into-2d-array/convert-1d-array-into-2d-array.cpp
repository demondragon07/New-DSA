class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n));
        vector<vector<int>>khali;
          int k=0;
          long long prod=m*n;
          if(original.size()>prod){
            return khali;
          }
           if(original.size()<prod){
            return khali;
          }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(k!=original.size())
                ans[i][j]=original[k];
                k++;
            }
        }
        return ans;
    }
};