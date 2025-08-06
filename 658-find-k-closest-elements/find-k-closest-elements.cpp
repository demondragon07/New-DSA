class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        int n=arr.size();
        auto it=lower_bound(arr.begin(),arr.end(),x);
        int h=it-arr.begin();
        if(h==0)
         return vector<int>(arr.begin(),arr.begin()+k);
        if(h==n)
         return vector<int>(arr.end()-k,arr.end());
        int l=h-1;
    while(h-l<=k){
        if(l<0){
            h++;
        }
        else if(h>n){
            l--;
        }
        else if(abs(arr[l]-x)>abs(arr[h]-x)){
           h++;
         }else{
             l--;
         }
      }

      return vector<int>(arr.begin()+l+1,arr.begin()+h);
    }
};