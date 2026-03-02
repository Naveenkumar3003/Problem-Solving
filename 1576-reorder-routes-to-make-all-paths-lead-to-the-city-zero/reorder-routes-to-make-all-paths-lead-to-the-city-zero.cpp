class Solution {
public:
    int dfs(int node,vector<vector<pair<int,int>>> &adj,vector<bool> &visited){
        visited[node]=true;
        int changes=0;
        for(auto &neighbour: adj[node]){
            int next=neighbour.first;
            int cost=neighbour.second;

            if(!visited[next]){
                changes+=cost;
                changes+=dfs(next,adj,visited);
            }
        }
        return changes;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &c: connections){
            int a=c[0],b=c[1];

            adj[a].push_back({b,1});
            adj[b].push_back({a,0});
        }
        vector<bool> visited(n,false);
        return dfs(0,adj,visited);
    }
};