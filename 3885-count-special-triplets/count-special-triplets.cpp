class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>l,r;
        int n=nums.size();
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            r[nums[i]]++;
        }
        for(int j=0;j<n;j++){
            int mid=nums[j];
            r[mid]--;
            int left=l[2*mid];
            int right=r[2*mid];
            ans=((ans+(1LL*left*right)%MOD)%MOD);
            l[mid]++;
        }
        return ans; 
    }
};