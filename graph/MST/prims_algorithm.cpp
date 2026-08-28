class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(V);

        // Build adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // {weight, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> visited(V, 0);

        // Start from node 0
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            // Already included in MST
            if (visited[node])
                continue;

            // Include node
            visited[node] = 1;
            sum += wt;

            // Add all adjacent edges
            for (auto neigh : adj[node]) {

                int nextNode = neigh.first;
                int edgeWeight = neigh.second;

                if (!visited[nextNode]) {
                    pq.push({edgeWeight, nextNode});
                }
            }
        }

        return sum;
    }
};
