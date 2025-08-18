class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
     long long MOD=1e9+7;
        int n=nums.size();
        for(auto x:queries){
            int li=x[0];
            int ri=x[1];
            int ki=x[2];
            int vi=x[3];
           while(li<=ri){
             nums[li]=(1LL*nums[li]*vi)%MOD;
             li+=ki;
           }
        }
        int ans=nums[0];
        for(int i=1;i<n;i++){
         ans=ans^nums[i];
        }
        return ans;
    }
};