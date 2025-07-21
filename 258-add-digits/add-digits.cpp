class Solution {
public:
    int addDigits(int num) {
        int newnumber=0;
        while(num>9){
            while(num>0){
            int digit=num%10;
             newnumber+=digit;
             num=num/10;
        }
        num=newnumber;
        newnumber=0;
        }
       return num; 
    }
};