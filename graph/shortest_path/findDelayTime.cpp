class Solution {
public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V + 1);

        // {destination, weight}
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(V, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto neigh : adj[node]) {

                int next = neigh.first;
                int weight = neigh.second;

                if (d + weight < dist[next]) {

                    dist[next] = d + weight;

                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < V; i++) {

            if (dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
