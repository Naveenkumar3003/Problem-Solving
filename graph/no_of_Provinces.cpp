class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int> &visited){
        visited[node]=1;
        for(auto neigh: adj[node]){
            if(!visited[neigh]){
                visited[neigh]=1;
                dfs(neigh,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        //Conversion to adj list
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(adj.size(),0);
        int cnt=0;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};
