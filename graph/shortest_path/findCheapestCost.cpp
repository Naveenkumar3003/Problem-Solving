class Solution {
  public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto elem=q.front();
            q.pop();
            int steps=elem.first;
            int node=elem.second.first;
            int cost=elem.second.second;
            
            if(steps>k) continue;
            for(auto neigh: adj[node]){
                int adjNode=neigh.first;
                int adjcost=neigh.second;
                
                if(cost+adjcost < dist[adjNode]){
                    dist[adjNode]=cost+adjcost;
                    q.push({steps+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};
