class Solution {
  public:
    void helper(int node,vector<vector<int>> &adj,
                vector<int>& visited,vector<int> &ans){
        visited[node]=1;
        ans.push_back(node);
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                helper(neigh,adj,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> ans;
        vector<int> visited(n,0);
        helper(0,adj,visited,ans);
        return ans;
    }
};
