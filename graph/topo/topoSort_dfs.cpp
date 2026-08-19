class Solution {
  public:
    void helper(int node,vector<vector<int>> &adj,
                vector<int>& visited,stack<int> &st){
        visited[node]=1;
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                helper(neigh,adj,visited,st);
            }
        }
        st.push(node);
    }
// TC - O(V+E), SC- O(2V)
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        int n=adj.size();
        stack<int> st;
        vector<int> ans;
        vector<int> visited(n,0);
        helper(0,adj,visited,st);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
