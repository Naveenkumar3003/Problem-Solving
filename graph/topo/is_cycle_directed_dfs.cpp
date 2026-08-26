class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adj) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int neigh : adj[node]) {

            // Node is not visited
            if (!vis[neigh]) {
                if (dfs(neigh, vis, pathVis, adj) == true) {
                    return true;
                }
            }

            // Node is already visited and is in current DFS path
            else if (pathVis[neigh]) {
                return true;
            }
        }

        // Remove node from current DFS path
        pathVis[node] = 0;

        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        vector<vector<int>> adj(V);

        // Create adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Check every component
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj) == true) {
                    return true;
                }
            }
        }

        return false;
    }
};
