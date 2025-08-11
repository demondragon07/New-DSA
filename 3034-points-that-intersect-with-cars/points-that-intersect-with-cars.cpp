class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
           if(nums[i][0]<=ans.back()[1]){
             ans.back()[0]=min(ans.back()[0],nums[i][0]);
             ans.back()[1]=max(ans.back()[1],nums[i][1]);
           }else
           ans.push_back({nums[i][0],nums[i][1]});
        }
        
        int m=ans.size();
        int sum=0;
        for(int i=0;i<m;i++){
           sum+=ans[i][1]-ans[i][0]+1;
        }
            return sum;
    }
};