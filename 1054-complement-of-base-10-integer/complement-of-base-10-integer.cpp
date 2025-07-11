class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        long long num_bits=(long long)log2(n)+1;
        for(int i=0;i<num_bits;i++){
            n=n^(1<<i);
        }
       return n; 
    }
};