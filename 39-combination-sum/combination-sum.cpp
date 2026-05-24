class Solution {
public:

    void solve(vector<vector<int>>&ans,vector<int>&arr ,int target,int i , vector<int>&ds){
           if(i==arr.size()){
              if(target==0) ans.push_back(ds);
              return;
           }

           if(arr[i]<=target){
            ds.push_back(arr[i]);
            solve(ans,arr,target-arr[i],i,ds);
            ds.pop_back();
           }
           solve(ans,arr,target,i+1,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int idx=0;
        solve(ans,candidates,target,idx,ds);
        return ans;
    }
};