class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        int sum=0;
        int n=logs.size();
         for(auto  it=logs.begin();it<logs.end();it++)
         {
            int firstnumber=(*it)[0];
            int lastnumber=(*it)[1];
            mp[firstnumber]++;
            mp[lastnumber]--;

         } 

     int ans=0;
     int result=0;
        for(auto x:mp)
         {
           sum+=x.second;
           if(sum>result){
            ans=x.first;
            result=sum;
           } 
         } 
       return ans;
    }
};