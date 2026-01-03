class Solution {
public:

    static bool mycmp(pair<char,int>&a, pair<char,int>&b){
           return a.second>b.second;
     }

    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){ 
            mp[s[i]]++;
        }
        vector<pair<char,int>>v;
        for(auto x:mp){
          v.push_back(x);
        }
        sort(v.begin(),v.end(),mycmp);
        string ans="";
       for(auto x:v){
        while(x.second){
          ans+=x.first;
          x.second--;
         }
       }
       return ans;
    }
};