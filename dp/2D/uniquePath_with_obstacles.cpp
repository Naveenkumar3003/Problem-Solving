class Solution {
public:
    
    // Recursion
    // int paths(int i,int j, vector<vector<int>>& grid){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0 || grid[i][j]==1) return 0;
    //     int up=paths(i-1,j,grid);
    //     int left=paths(i,j-1,grid);
    //     return up+left;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     return paths(n-1,m-1,grid);
    // }

    // Memoization
    // int paths(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0 || grid[i][j]==1) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=paths(i-1,j,grid,dp);
    //     int left=paths(i,j-1,grid,dp);
    //     return dp[i][j]=up+left;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return paths(n-1,m-1,grid,dp);
    // }

    // Tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else if(grid[i][j]==1) dp[i][j]=0;
                else{
                    int up=(i>0)?dp[i-1][j]:0;
                    int left=(j>0)?dp[i][j-1]:0;
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
