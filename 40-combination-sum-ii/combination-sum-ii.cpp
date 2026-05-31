class Solution {
public:
    void findcombination(vector<vector<int>>&ans, vector<int>&ds, int idx, int target,vector<int>arr){
        if(target==0){
            ans.push_back(ds);
            return;
            }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[i]>target) return;
            ds.push_back(arr[i]);
            findcombination(ans,ds,i+1,target-arr[i],arr);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        findcombination(ans,ds,0,target,candidates);
        return ans;

    }
};