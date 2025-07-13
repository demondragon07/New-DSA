class Solution {
public:
    vector<int> evenOddBit(int n) {
        int num_bits=(int)log2(n)+1;
        vector<int>ans(2,0);
        int even=0;
        int odd=0;
        for(int i=0;i<num_bits;i++){
          if(n&1){
             if(i&1){
                odd++;
             }else{
                even++;
             }
          }
          n=n>>1;
        }
        ans[0]=even;
        ans[1]=odd;
        return ans;
    }
};