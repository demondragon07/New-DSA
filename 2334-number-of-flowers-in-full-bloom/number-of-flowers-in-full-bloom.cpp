class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mp;
        for(auto x:flowers){
            mp[x[0]]++;
            mp[x[1]+1]--;
        }
        vector<pair<int,int>>p;
        int current=0;
        for(auto x:mp){
          current+=x.second;
          p.push_back({x.first,current});
        }

       vector<int>ans;
       for(auto x:people){
          auto it=lower_bound(p.begin(),p.end(),make_pair(x,INT_MIN));
          if(it==p.end())
           ans.push_back(0);
          else if((*it).first==x){
            ans.push_back((*it).second);
          }
          else if((*it).first>x){
             if(it!=p.begin()){
                it--;
                ans.push_back((*it).second);
             }
             else if(it==p.begin()){
                ans.push_back(0);
             }
          }       
       }
       return ans;
    } 
};