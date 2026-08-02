class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& visited){
        visited[i][j]=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && !visited[nr][nc]){
                    dfs(nr,nc,grid,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> ans(n,vector<int>(m));
        vector<vector<int>> visited(n,vector<int>(m));
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(0,j,grid,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1 && !visited[n-1][j]){
                dfs(n-1,j,grid,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
