class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minimum=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
         profit=max(profit,prices[i]-minimum);
           if(prices[i]<minimum)
             minimum=prices[i];
        }
        return profit;
    }
};