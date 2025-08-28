class Solution {
public:

  bool isvalid(vector<int>&nums,long long mid){
    vector<long long>arr(nums.begin(),nums.end());
    long long n=arr.size();
    for(long long i=0;i<n-1;i++){
        if(arr[i]>mid)return false;
        long long buffer=mid-arr[i];
        arr[i+1]=arr[i+1]-buffer;
    }
   return arr[n-1]<=mid;
  }
    int minimizeArrayValue(vector<int>& nums) {
       int s=0;
       int e=*max_element(nums.begin(),nums.end());
       while(s<e){
         long long mid=s+(e-s)/2;
        if(isvalid(nums,mid))e=mid;
           else s=mid+1;
        }
    return s;
    }
};