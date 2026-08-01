class Solution {
  public:
    //  RECURSION  
    // int helper(int day,int last,vector<vector<int>>& mat){
    //     if(day==mat.size()-1){
    //         int maxi=INT_MIN;
    //         for(int i=0;i<=2;i++){
    //             if(i!=last){
    //                 int points=mat[day][i];
    //                 maxi=max(maxi,points);
    //             }
    //         }
    //         return maxi;
    //     }
    //     int maxi=INT_MIN;
    //     for(int i=0;i<=2;i++){
    //         if(i!=last){
    //             int points=mat[day][i]+helper(day+1,i,mat);
    //             maxi=max(maxi,points);
    //         }
    //     }
    //     return maxi;
    // }
    // int maximumPoints(vector<vector<int>>& mat) {
    //     // code here
    //     return helper(0,3,mat);
    // }
    
    // Memoization
    // int helper(int day,int last,vector<vector<int>>& mat,vector<vector<int>> &dp){
    //     if(day==mat.size()-1){
    //         int maxi=INT_MIN;
    //         for(int i=0;i<=2;i++){
    //             if(i!=last){
    //                 int points=mat[day][i];
    //                 maxi=max(maxi,points);
    //             }
    //         }
    //         return maxi;
    //     }
    //     if(dp[day][last]!=-1) return dp[day][last];
    //     int maxi=INT_MIN;
    //     for(int i=0;i<=2;i++){
    //         if(i!=last){
    //             int points=mat[day][i]+helper(day+1,i,mat,dp);
    //             maxi=max(maxi,points);
    //         }
    //     }
    //     return dp[day][last]=maxi;
    // }
    
    // int maximumPoints(vector<vector<int>>& mat) {
    //     vector<vector<int>> dp(mat.size(),vector<int> (3,-1));
    //     return helper(0,3,mat,dp);
    // }
    
    //Tabulation
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max({mat[0][0], mat[0][1], mat[0][2]});

        for(int day = 1; day < n; day++) {

            for(int last = 0; last < 4; last++) {

                dp[day][last] = 0;

                for(int task = 0; task < 3; task++) {

                    if(task != last) {

                        dp[day][last] = max(
                            dp[day][last],
                            mat[day][task] + dp[day-1][task]
                        );
                    }
                }
            }
        }

        return dp[n-1][3];
    }
};
