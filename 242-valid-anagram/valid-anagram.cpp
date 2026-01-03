class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int>arr(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch1=s[i];
            char ch2=t[i];
            arr[ch1-'a']++;
            arr[ch2-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0)return false;
        }
        return true;
    }
};