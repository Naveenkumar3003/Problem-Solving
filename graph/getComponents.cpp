class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &curr){
        visited[node]=1;
        curr.push_back(node);
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                dfs(neigh,adj,visited,curr);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // convert to adj list
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,curr);
                ans.push_back(curr);
                curr={};
            }
        }
        return ans;
    }
};
