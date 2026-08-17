class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        vector<int>mp(26,0);
        for(auto &it:tasks){
            mp[it-'A']++;
        }

        priority_queue<int>pq;
        for(auto x:mp){
            if(x>0)pq.push(x);
        }
      
      while(!pq.empty()){
        vector<int>temp;
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }

        for(auto x:temp){
            if(x>0)pq.push(x);
        }

        if(!pq.empty())time+=n+1;
        else time+=temp.size();

      }
      return time;
    }
};