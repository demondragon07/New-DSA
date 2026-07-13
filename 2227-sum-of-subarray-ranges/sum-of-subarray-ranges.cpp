class Solution {
public:
    long long sumofnge(vector<int>&nums){
        int n=nums.size();
        vector<int>nge(n);
        vector<int>ngpee(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i])st.pop();
            ngpee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-ngpee[i];
            int right=nge[i]-i;
            total+=(left*right*1LL*nums[i]);
        }
        return total;
    }
    long long sumofnse(vector<int>&nums){
        int n=nums.size();
        vector<int>nse(n);
        vector<int>nspee(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i])st.pop();
            nspee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-nspee[i];
            int right=nse[i]-i;
            total+=(left*right*1LL*nums[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
     return sumofnge(nums)-sumofnse(nums); 
    }
};