class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
       
       int startingrow=0;
       int startingcolumn=0;
       int endingrow=n-1;
       int endingcolumn=m-1;
       int totalelement=m*n;
       int count=0;

     while(count<totalelement){
       for(int i=startingcolumn;i<=endingcolumn && count<totalelement;i++){
          ans.push_back(matrix[startingrow][i]);
          count++;
       }
       startingrow++;

       for(int i=startingrow;i<=endingrow && count<totalelement;i++){
          ans.push_back(matrix[i][endingcolumn]);
          count++;
       }
      endingcolumn--;

       for(int i=endingcolumn;i>=startingcolumn && count<totalelement;i--){
          ans.push_back(matrix[endingrow][i]);
          count++;
       }
       endingrow--;
       
       for(int i=endingrow;i>=startingrow && count<totalelement;i--){
        ans.push_back(matrix[i][startingcolumn]);
        count++;
       }
       startingcolumn++;
      }
    return ans;
  } 
};