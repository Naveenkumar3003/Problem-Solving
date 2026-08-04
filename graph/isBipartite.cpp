class Solution {
  public:
    // Similar to cycle detection
    bool dfs(int node,int col,vector<int> &visited,vector<vector<int>> &adj){
        visited[node]=col;
        for(int neigh:adj[node]){
            if(visited[neigh]==-1){
                if(!dfs(neigh,!col,visited,adj)) return false;
            }
            else if(visited[neigh]==col) return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(V,-1);
        
        for(int i=0;i<V;i++){
            if(visited[i]==-1){
                if(!dfs(i,0,visited,adj)) return false;
            }
        }
        return true;
    }
};
