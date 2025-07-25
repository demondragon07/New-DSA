class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v;
        for(int j=0;j<m;j++){
            int maxans=0;
            for(int i=0;i<n;i++){
              int temp=matrix[i][j];
             if(temp>maxans){
                maxans=temp;
              }
            } 
            v.push_back(maxans);
        }

int k=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(matrix[i][j] ==-1){
                    matrix[i][j]=v[k];
                }
            }
            k++;
        }
       return matrix; 
    }
};