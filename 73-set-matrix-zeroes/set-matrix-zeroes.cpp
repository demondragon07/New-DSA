class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        bool isfirstrowimpacted=false;
        bool isfirstcolumnimpacted=false;

        for(int i=0;i<1;i++){
            for(int j=0;j<m;j++){
              if(matrix[i][j]==0){
               isfirstrowimpacted=true;
               break;
              } 
            }
        }

       for(int j=0;j<1;j++){
        for(int i=0;i<n;i++){
            if(matrix[i][j]==0){
            isfirstcolumnimpacted=true;
            break;
            }
        }
       } 
         
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
              if(matrix[i][j]==0){
                 matrix[i][0]=0;
                 matrix[0][j]=0;
              }
            }
        }
       for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
       } 

      if(isfirstrowimpacted){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
      } 

      if(isfirstcolumnimpacted){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
      }
    }
};