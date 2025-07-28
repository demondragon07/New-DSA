class Solution {
public:

    long long find(string s){
         int n=s.length();
         vector<int>leftkaL(n,0);
         vector<int>rightkaT(n,0);
      
      if(s[0]=='L'){
        leftkaL[0]=1;
      }
         for(int i=1;i<n;i++){
            if(s[i]=='L')
            leftkaL[i]=leftkaL[i-1]+1;
            else
            leftkaL[i]=leftkaL[i-1];
           
         } 

         if(s[n-1]=='T'){
            rightkaT[n-1]=1;
         }
         for(int i=n-2;i>=0;i--){
            if(s[i]=='T')
            rightkaT[i]=rightkaT[i+1]+1;
         else
            rightkaT[i]=rightkaT[i+1];
         }
     
      long long ans=0;
       for(int i=0;i<n;i++){
        if(s[i]=='C'){
          ans+=(1LL)*leftkaL[i]*rightkaT[i];
        }
       }

        return ans;  
    }

    long long numOfSubsequences(string s) {
        long long ans1=find('L'+s);
        long long ans2=find(s+'T');
        long long ans3=find(s);

       int n=s.size();
       vector<int>leftkaL(n,0);
       vector<int>rightkaT(n,0);

       if(s[0]=='L'){
          leftkaL[0]=1;
       }

       for(int i=1;i<n;i++){
        if(s[i]=='L')
         leftkaL[i]=leftkaL[i-1]+1;
       else
        leftkaL[i]=leftkaL[i-1];
       }

       if(s[n-1]=='T'){
        rightkaT[n-1]=1;
       }
        
       for(int i=n-2;i>=0;i--){
        if(s[i]=='T')
         rightkaT[i]=rightkaT[i+1]+1;
        else
        rightkaT[i]=rightkaT[i+1]; 
       }

      long long maxi=0;
       for(int i=0;i<n;i++){
        long long temp=(long long)leftkaL[i]*(long long)rightkaT[i];
           maxi=max(maxi,temp);
        }
     ans3+=maxi;

        long long ans=max({ans1,ans2,ans3});
        return ans;
    }
};