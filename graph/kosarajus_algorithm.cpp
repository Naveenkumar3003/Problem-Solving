class Solution {
  private:
    void dfs(int &node,vector<int> &vis,vector<vector<int>> &adj,stack<int> &st){
        vis[node]=1;
        for(int neigh:adj[node]){
            if(!vis[neigh]) dfs(neigh,vis,adj,st);
        }
        st.push(node);
    }
    void dfs2(int &node,vector<int> &vis,vector<vector<int>> &adj){
        vis[node]=1;
        for(int neigh:adj[node]){
            if(!vis[neigh]) dfs2(neigh,vis,adj);
        }
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,vis,adjT);
            }
        }
        return scc;
    }
};
