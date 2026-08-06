class Solution {
  public:
    // Recursion 
    // int mod = 1e9 + 7;

    // int solve(int ind, int target, vector<int>& arr) {

    //     // Base Case
    //     if (ind == 0) {

    //         // Two subsets: {} and {0}
    //         if (target == 0 && arr[0] == 0)
    //             return 2;

    //         // Empty subset
    //         if (target == 0)
    //             return 1;

    //         // Take first element
    //         if (arr[0] == target)
    //             return 1;

    //         return 0;
    //     }

    //     int notTake = solve(ind - 1, target, arr);

    //     int take = 0;
    //     if (arr[ind] <= target)
    //         take = solve(ind - 1, target - arr[ind], arr);

    //     return (take + notTake) % mod;
    // }

    // int perfectSum(vector<int>& arr, int sum) {

    //     int n = arr.size();

    //     return solve(n - 1, sum, arr);
    // }
    
    // Memoization
    // int mod = 1e9 + 7;

    // int solve(int ind, int target,
    //           vector<int>& arr,
    //           vector<vector<int>>& dp) {

    //     // Base Case
    //     if (ind == 0) {

    //         if (target == 0 && arr[0] == 0)
    //             return 2;

    //         if (target == 0)
    //             return 1;

    //         if (arr[0] == target)
    //             return 1;

    //         return 0;
    //     }

    //     if (dp[ind][target] != -1)
    //         return dp[ind][target];

    //     int notTake = solve(ind - 1, target, arr, dp);

    //     int take = 0;
    //     if (arr[ind] <= target)
    //         take = solve(ind - 1, target - arr[ind], arr, dp);

    //     return dp[ind][target] = (take + notTake) % mod;
    // }

    // int perfectSum(vector<int>& arr, int sum) {

    //     int n = arr.size();

    //     vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    //     return solve(n - 1, sum, arr, dp);
    // }
    
    
    // Tabulation
    int mod = 1e9 + 7;

    int perfectSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // If first element is 0:
        // {} and {0} both have sum = 0, so there are 2 subsets.
        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {

            for (int j = 0; j <= sum; j++) {

                int notTake = dp[i - 1][j];

                int take = 0;

                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = (take + notTake) % mod;
            }
        }

        return dp[n - 1][sum];
    }
};
