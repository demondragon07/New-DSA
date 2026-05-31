class Solution {
public:

    void findallcombos(vector<vector<int>>&ans,vector<int>ds,vector<int>arr,int k, int n ,int i){
        if(n==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i<arr.size()){
        ds.push_back(arr[i]);
        findallcombos(ans,ds,arr,k,n-arr[i],i+1);
        ds.pop_back();
        findallcombos(ans,ds,arr,k,n,i+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        findallcombos(ans,ds,arr,k,n,0);
        return ans;
    }
};