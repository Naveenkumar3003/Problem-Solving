class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (d > totalSum || (totalSum + d) % 2)
            return 0;
        int sum = (totalSum + d) / 2;
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
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
                dp[i][j] = (take + notTake) % MOD;
            }
        }
        return dp[n - 1][sum];
    }
};
