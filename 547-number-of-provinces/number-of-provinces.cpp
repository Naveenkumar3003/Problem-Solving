class Solution {
public:
    void dfs(int city,vector<bool> &visited,vector<vector<int>> &isConnected){
        visited[city]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[city][i]==1 && !visited[i]){
                dfs(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int province=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                province++;
            }
        }
        return province;
    }
};