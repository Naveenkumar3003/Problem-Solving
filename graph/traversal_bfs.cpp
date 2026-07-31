vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int> ans;
        vector<int> visited(n+1,0);
        queue<int> q;
        visited[0]=1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
            
        }
        return ans;
    }
