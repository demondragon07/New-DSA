class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
      unordered_map<int,vector<int>>adj;
      unordered_map<int,int>indegree;
      unordered_map<int,int>outdegree;
      for(auto x:pairs){
        int u=x[0];
        int v=x[1];
        adj[u].push_back(v);
        indegree[v]++;
        outdegree[u]++; 
      }

      int startingnode=pairs[0][0];
      for(auto x:pairs){
        int u=x[0];
        if(outdegree[u]-indegree[u]==1) {
            startingnode=u;
            break;
        }
      }
      
      vector<int>ep;
      stack<int>st;
     
     st.push(startingnode);
     while(!st.empty()){
        int u=st.top();
        if(!adj[u].empty()){
            int v=adj[u].back();
            st.push(v);
            adj[u].pop_back();
        }else{
            ep.push_back(u);
            st.pop();
        }
     }

     reverse(ep.begin(),ep.end());
    vector<vector<int>>result;  
     for(int i=0;i<ep.size()-1;i++){
        result.push_back({ep[i],ep[i+1]});
     }
   return result;
    }
};