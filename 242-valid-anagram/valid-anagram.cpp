class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp1;
        map<char,int>mp2;
        if(s.size()!=t.size())return false;
        int m=s.size();
        for(int i=0;i<m;i++){
            char ch1=s[i];
            char ch2=t[i];
            mp1[ch1]++;
            mp2[ch2]++;
        }
    return mp1==mp2;
    }
};