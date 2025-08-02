class Solution {
public:
     int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b){
               return gcd(b,a);
            }
            b=b-a; 
        }
        return a==0?b:a;
     }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int smallest=nums[0];
        int largest=nums[n-1];
        return gcd(smallest,largest);
    }
};