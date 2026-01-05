class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int n=cardPoints.size();
        int ridx=n-1;
        lsum=accumulate(cardPoints.begin(), cardPoints.begin()+k,0);
        int ans=lsum;
        for(int i=k-1;i>=0;i--){
           lsum-=cardPoints[i];
           rsum+=cardPoints[ridx];
           ridx--;
           ans=max(ans,lsum+rsum);
        }
      return ans;
    }
};