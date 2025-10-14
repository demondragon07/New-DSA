class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
         vector<int>indegree(numCourses,0);
         for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
         }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
         vector<int>result;
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            q.pop();
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v); 
            }
        }
        if(result.size()!=numCourses) return false;
        return true;
    }
};