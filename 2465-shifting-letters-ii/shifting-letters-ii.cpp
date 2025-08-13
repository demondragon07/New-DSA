class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n,0);

        for(auto query:shifts){
            int L=query[0];
            int R=query[1];
            int x;
            if(query[2]==0)
            x=-1;
            else 
            x=1;
            
            diff[L]+=x;
            if(R+1<n)
            diff[R+1]-=x;
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<n;i++){
            diff[i]=diff[i]%26;
            if(diff[i]<0){
              diff[i]+=26;
            }
           s[i]=(((s[i]-'a')+diff[i])%26)+'a'; 
        }
        return s;
    }
};