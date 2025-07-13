class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int e=m*n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int i=mid/m;
            int j=mid%m;
            if(matrix[i][j]==target){
                return 1;
            }else if(matrix[i][j]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return false;
    }
};