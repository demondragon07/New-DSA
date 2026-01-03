class Solution {
public:
 static bool mycmp(pair<char,int>&a, pair<char,int>&b){
    return a.second>b.second;
 }
    string frequencySort(string s) {
        vector<pair<char,int>>v(123);
        int n=s.length();
        for(int i=0;i<n;i++){
            v[s[i]].first=s[i];
            v[s[i]].second++;
        } 
        sort(v.begin(),v.end(),mycmp);
        string result="";
        for(int i=0;i<122;i++){
            if(v[i].second>0){
                char ch=v[i].first;
                int freq=v[i].second;
                string temp=string(freq,ch);
                result+=temp;
            }
        }
        return result;
    }
};