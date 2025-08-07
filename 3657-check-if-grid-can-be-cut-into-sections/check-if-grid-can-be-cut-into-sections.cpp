class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
           if(intervals[i][0]<ans.back()[1]){
              ans.back()[1]=max(intervals[i][1],ans.back()[1]);
               
           }else{
             ans.push_back(intervals[i]);
           } 
        }
     return ans;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>hor;
        vector<vector<int>>vert;
        for(auto cord:rectangles){
            int x1=cord[0];
            int y1=cord[1];
            int x2=cord[2];
            int y2=cord[3];
            hor.push_back({x1,x2});
            vert.push_back({y1,y2});
        }
    
    vector<vector<int>>result1=merge(hor);
    vector<vector<int>>result2=merge(vert);

    return result1.size()>=3 || result2.size()>=3;
    }
};