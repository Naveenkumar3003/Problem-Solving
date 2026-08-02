class Solution {
public:

    // Recusion
    // long long pathsum(int i,int j,vector<vector<int>> &grid){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0) return 1e9;
    //     long long up=grid[i][j]+pathsum(i-1,j,grid);
    //     long long left=grid[i][j]+pathsum(i,j-1,grid);
    //     return min(up,left);
    // }
    // int minPathSum(vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     return (int)pathsum(n-1,m-1,grid);
    // }

    // memoization
    // long long pathsum(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0) return 1e9;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     long long up=grid[i][j]+pathsum(i-1,j,grid,dp);
    //     long long left=grid[i][j]+pathsum(i,j-1,grid,dp);
    //     return dp[i][j]=min(up,left);
    // }
    // int minPathSum(vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return (int)pathsum(n-1,m-1,grid,dp);
    // }

    // Tabulation
    int minPathSum(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=(i>0)?grid[i][j]+dp[i-1][j]:INT_MAX;
                    int left=(j>0)?grid[i][j]+dp[i][j-1]:INT_MAX;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
