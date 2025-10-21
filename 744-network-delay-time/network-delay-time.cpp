class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     unordered_map<int,vector<pair<int,int>>>adj;
     for(auto x:times){
        adj[x[0]].push_back({x[1],x[2]});
     }
     
     vector<int>result(n+1,INT_MAX);
     result[k]=0;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     pq.push({0,k});
     while(!pq.empty()){
        pair<int,int>p=pq.top();
        int u=p.second;
        int dist=p.first;
        pq.pop();
        for(auto v:adj[u]){
            int node=v.first;
            int d=v.second;
            if(d+dist<result[node]){
                result[node]=d+dist;
                pq.push({d+dist,node});
            }
        }
     }
    int ans=-1;
    for(int i=1;i<=n;i++)ans=max(ans,result[i]);
    if(ans==INT_MAX) return -1;
    
    return ans;
    }
};