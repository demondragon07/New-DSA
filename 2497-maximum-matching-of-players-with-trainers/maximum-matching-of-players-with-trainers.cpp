class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l=0;
        int r=0;
        int ans=0;
        while(l<players.size() && r<trainers.size()){
            if(trainers[r]>=players[l]){
                ans++;
                r++;
                l++;
            }else r++;
        }
        return ans;
    }
};