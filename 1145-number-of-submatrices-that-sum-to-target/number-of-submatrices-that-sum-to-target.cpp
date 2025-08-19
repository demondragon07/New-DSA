class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
             matrix[i][j]+=matrix[i][j-1];
            }
        }

        for(int sc=0;sc<m;sc++){
            for(int j=sc;j<m;j++){
                unordered_map<int,int>mp;
                mp.insert({0,1});
                int cumsum=0;
                 for(int i=0;i<n;i++){
                 cumsum+=matrix[i][j]-(sc>0?matrix[i][sc-1]:0);
                    if(mp.find(cumsum-target)!=mp.end()){
                        result+=mp[cumsum-target];
                    }
                    mp[cumsum]++;
                 }
              }
           } 
         return result;     
    }
};