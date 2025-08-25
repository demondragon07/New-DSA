class Solution {
public:
bool ispossible(vector<int>piles,int mid,int h){
    int ct=0;
    for(auto x:piles){
         ct += (x+mid-1)/mid;   // ceil(x/mid)
    }
    if(ct>h) return false;
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(ispossible(piles,mid,h)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};