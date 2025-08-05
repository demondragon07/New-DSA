class Solution {
public:
    static int x_global;
    static bool mysort(int a ,int b){
    if(abs(a-x_global)==abs(b-x_global))
    return a<b;
    return abs(a-x_global)<abs(b-x_global);
   }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
         vector<int>ans;
        x_global=x;
      sort(arr.begin(),arr.end(),mysort);

    for(int i=0;i<k;i++){
       ans.push_back(arr[i]);
    }

    sort(ans.begin(),ans.end());
    return ans;
    } 
};
 int Solution::x_global=0;