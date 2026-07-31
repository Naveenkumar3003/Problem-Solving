class Solution {
  public:
    bool detect(int node,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
            int curr=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int neigh: adj[curr]){
                if(!visited[neigh]){
                    visited[neigh]=1;
                    q.push({neigh,curr});
                }
                else if(parent!=neigh) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
       
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
        
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i,adj,visited)) return true;
            }
        }
        return false;
    }
};
