class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        int n=trips.size();
        int sum=0;
      for(int i=0;i<n;i++){
        mp[trips[i][1]]+=trips[i][0];
        mp[trips[i][2]]+=0-trips[i][0];
      }
      for(auto x:mp){
        sum+=x.second;
        if(sum>capacity){
            return false;
        }
      }
      return true;
    }
};