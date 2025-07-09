class Solution {
public:
    int hIndex(vector<int>& citations) {
       int s=0;
       int n=citations.size();
       int e=n-1;
       while(s<=e){
        int mid=s+(e-s)/2;
        if(citations[mid]==n-mid){
            return n-mid;
        }
        else if(citations[mid]>n-mid){
            e=mid-1;
        }else{
            s=mid+1;
        }
       }
       return n-s;
    }
};