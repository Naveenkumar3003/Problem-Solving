class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<long long> dist(V,1e9);
        vector<int> ways(V);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            
            for(auto neigh:adj[node]){
                int next=neigh.first;
                long long dis=neigh.second;
                if(dis+d<dist[next]){
                    dist[next]=dis+d;
                    ways[next]=ways[node];
                    pq.push({dist[next],next});
                }
                else if(dis+d==dist[next]){
                    ways[next]+=ways[node];
                }
            }
        }
        return ways[V-1];
        
    }
};
