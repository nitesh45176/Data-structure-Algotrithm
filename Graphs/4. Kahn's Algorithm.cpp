
class Solution {

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<int> indegree(V,0);
       
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0; i<V; i++){
            for(auto adjNode: adj[i]){
                indegree[adjNode]++;
        }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
            
            
        }
    return topo;
    }
};
