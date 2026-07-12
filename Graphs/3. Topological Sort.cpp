
class Solution {
  private:
    void dfs(int node, vector<int>& vis, stack<int> &st, unordered_map<int, list<int>>& adj) {
        vis[node] = 1;
        
        for(auto adjNode: adj[node]){
            if(vis[adjNode] == 0){
                dfs(adjNode, vis, st, adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V,0);
        stack<int> st;
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
