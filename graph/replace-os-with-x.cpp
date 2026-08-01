class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>> &ans,
                vector<vector<char>> &grid){
        visited[i][j]=1;
        ans[i][j] = 'O';
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && 
                    !visited[nr][nc] && grid[nr][nc]=='O'){
                        dfs(nr,nc,visited,ans,grid);
            }
        }
    }
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> visited(n,(vector<int>(m)));
         // First row
        for(int j = 0; j < m; j++)
            if(grid[0][j] == 'O' && !visited[0][j])
                dfs(0, j, visited, ans, grid);

        // Last row
        for(int j = 0; j < m; j++)
            if(grid[n-1][j] == 'O' && !visited[n-1][j])
                dfs(n-1, j, visited, ans, grid);

        // First column
        for(int i = 0; i < n; i++)
            if(grid[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, visited, ans, grid);

        // Last column
        for(int i = 0; i < n; i++)
            if(grid[i][m-1] == 'O' && !visited[i][m-1])
                dfs(i, m-1, visited, ans, grid);

        
        grid=ans;
    }
};
