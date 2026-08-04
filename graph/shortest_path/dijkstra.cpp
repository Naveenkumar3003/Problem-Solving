class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // MIN HEAP
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // vector<int> dist(V,1e9);
        
        // dist[src]=0;
        // pq.push({0,src});
        // while(!pq.empty()){
        //     int dis=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
        //     for(auto neigh:adj[node]){
        //         int edgeW=neigh.second;
        //         int adjNode=neigh.first;
        //         if(edgeW+dis<dist[adjNode]){ 
        //             dist[adjNode]=edgeW+dis;
        //             pq.push({dist[adjNode],adjNode});
        //         }
        //     }
        // }
        // return dist;
        
        // SET
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto elem=*(st.begin());
            int dis=elem.first;
            int node=elem.second;
            st.erase(elem);
            
            for(auto neigh: adj[node]){
                int edgeW=neigh.second;
                int adjNode=neigh.first;
                if(dis+edgeW<dist[adjNode]){
                    if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                    dist[adjNode]=edgeW+dis;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
