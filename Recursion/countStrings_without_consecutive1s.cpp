class Solution {
  public:
    // Recursion
    // int solve(int idx, int n, bool prevOne) {

    //     // One valid string is formed
    //     if (idx == n)
    //         return 1;

    //     // Always place 0
    //     int count = solve(idx + 1, n, false);

    //     // Place 1 only if previous wasn't 1
    //     if (!prevOne)
    //         count += solve(idx + 1, n, true);

    //     return count;
    // }

    // int countStrings(int n) {
    //     return solve(0, n, false);
    // }
    
    //DP
    int solve(int idx,int n,int prevOne,vector<vector<int>> &dp){
        if(idx==n) return 1;
        if(dp[idx][prevOne]!=-1) return dp[idx][prevOne];
        int cnt=solve(idx+1,n,0,dp);
        if(!prevOne){
            cnt+=solve(idx+1,n,1,dp);
        }
        return dp[idx][prevOne]=cnt;
    }
    int countStrings(int n) {
        int idx=0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(idx,n,0,dp);
    }
};
