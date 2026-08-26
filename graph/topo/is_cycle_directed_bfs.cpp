    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        int n = adj.size();
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> list;

        // Compute indegrees
        for (int i = 0; i < n; i++) {
            for (int next : adj[i])
                indegree[next]++;
        }

        // Add all nodes with indegree 0 
        // into the queue
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        // Kahn’s Algorithm (BFS)
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            list.push_back(top);
            for (int next : adj[top]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        if(list.size()==V) return false;
        return true;
        
    }
