class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
                while(!st.empty() && st.back()>num[i] && k)
                  {
                    st.pop_back();
                    k--;
                    }
                if(st.empty() && num[i]=='0') continue;
                else st.push_back(num[i]); 
        }
        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }
        string ans;
        for(int i=0;i<st.size();i++){
            ans+=st[i];
        }
      return ans.empty()?"0":ans;
    }
};