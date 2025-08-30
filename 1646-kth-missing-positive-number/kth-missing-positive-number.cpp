class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int num=1;
        while(i<n && k>0){
            if(arr[i]!=num){
                k--;
            }else if(arr[i]==num){
                i++;
            }
            num++;
        }
        while(k--){
            num++;
        }
        return num-1;
    }
};