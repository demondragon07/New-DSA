class Solution {
public:

    int ispossible(vector<int>&weights,int mid){
        int currdays=1;
        int n=weights.size();
        int currsum=0;
        for(auto x:weights){
            if(currsum+x>mid){
                currdays++;
                currsum=0;
            }
            currsum+=x;
        }
        return currdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int s=*max_element(weights.begin(),weights.end());
        sum+=accumulate(weights.begin(),weights.end(),0);
        int e=sum;
        while(s<e){
            int mid=s+(e-s)/2;
            if(ispossible(weights,mid)<=days){
                e=mid;
            }else{
                s=mid+1;
            }
        }
        return s;
    }
};