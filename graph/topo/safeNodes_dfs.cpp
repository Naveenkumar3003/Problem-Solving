class Solution {
  public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adj,vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node]=0;

        for (int neigh : adj[node]) {

            // Node is not visited
            if (!vis[neigh]) {
                if (dfs(neigh, vis, pathVis, adj,check) == true) {
                    check[node]=0;
                    return true;
                }
            }
            // Node is already visited and is in current DFS path
            else if (pathVis[neigh]) {
                check[node]=0;
                return true;
            }
        }

        // Remove node from current DFS path
        pathVis[node] = 0;
        check[node]=1;
        return false;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V,0);
        vector<int> safeNodes;
        vector<vector<int>> adj(V);

        // Create adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Check every component
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathVis, adj,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        
        return safeNodes;
        
    }
};
