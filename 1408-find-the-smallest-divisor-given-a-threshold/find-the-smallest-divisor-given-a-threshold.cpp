class Solution {
public:
    int ispossible(vector<int>&nums, int threshold, int mid){
        int count=0;
        for(auto x:nums){
            count+=ceil(x/(double)mid);
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        while(s<e){
            int mid=s+(e-s)/2;
            if(ispossible(nums,threshold,mid)<=threshold) e=mid;
            else s=mid+1;
        }
        return s;
    }
};