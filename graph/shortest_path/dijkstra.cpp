class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto neigh:adj[node]){
                int edgeW=neigh.second;
                int adjNode=neigh.first;
                if(edgeW+dis<dist[adjNode]){ 
                    dist[adjNode]=edgeW+dis;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
