class Solution {
public:

    int canbloom(vector<int>&bloomDay,int mid, int k){
         int n=bloomDay.size();
         int bouqetcount=0;
         int consecutivecount=0;
         for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consecutivecount++;
            }else{
               consecutivecount=0;
            }
            if(consecutivecount==k){
                bouqetcount++;
                consecutivecount=0;
            }
         }
     return bouqetcount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(canbloom(bloomDay,mid,k)>=m){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};