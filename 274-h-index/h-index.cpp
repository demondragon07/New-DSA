class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n=citations.size();
       vector<int>freq(n+1,0);
       for(int i=0;i<n;i++){
        if(citations[i]<=n){
            freq[citations[i]]++;

        }else{
            freq[n]++;
        }
       }
      int m=freq.size();
      int count=0;
      for(int i=m-1;i>=0;i--){
        count +=freq[i];
        if(count>=i){
            return i;
        }
      }

      return 0;
    }
};