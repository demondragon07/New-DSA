class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>revadj[n];
        vector<int>outdeg(n,0);
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                revadj[x].push_back(i);
                outdeg[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0)q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(int i=0;i<revadj[node].size();i++){
               outdeg[revadj[node][i]]--;
               if(outdeg[revadj[node][i]]==0)q.push(revadj[node][i]);
           }
        }
       sort(ans.begin(),ans.end());
       return ans;
    }
};