class Solution {
public:
    string generateTag(string caption) {
        string ans;
        ans.push_back('#');
        bool capt=false;
        for(auto x:caption){
            if(x==' '){
                if(ans.size()>1)capt=true;
            }else{
                if(capt){
                    ans.push_back(toupper(x));
                }else{
                    ans.push_back(tolower(x));
                }
                capt=false;
            }
           if(ans.size()==100){
            break;
           } 
        }
        return ans;
    }
};