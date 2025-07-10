class Solution {
public:
    int findComplement(int num) {
        int numbits=(int)log2(num)+1;

        for(int i=0;i<numbits;i++){
            num=num^(1<<i);
        }
       return num; 
    }
};