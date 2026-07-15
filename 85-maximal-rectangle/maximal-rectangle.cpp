class Solution {
public:
    vector<int>nextsmallerelement(vector<int>& arr){
       int n=arr.size();
       vector<int>nse(n);
       stack<int>st;
       for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
          nse[i]=st.empty()?n:st.top();
          st.push(i);
       }
       return nse;
    }

    vector<int>previoussmallerelement(vector<int>& arr){
       int n=arr.size();
       vector<int>pse(n);
       stack<int>st;
       for(int i=0;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i])st.pop();
          pse[i]=st.empty()?-1:st.top();
          st.push(i);
       }
       return pse;
    }

    int largeareainhistogram(vector<int>& heights){
        int n=heights.size();
        vector<int>nse=nextsmallerelement(heights);
        vector<int>pse=previoussmallerelement(heights);
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,(nse[i]-pse[i]-1)*heights[i]);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       vector<int>height(m,0);
       int maxarea=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1')height[j]++;
            else height[j]=0;
        }
        int area=largeareainhistogram(height);
        maxarea=max(maxarea,area);
       }
       return maxarea; 
    }
};