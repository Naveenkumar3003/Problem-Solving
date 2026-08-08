class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        const long long LIMIT = INT_MAX;

        vector<vector<long long>> dp(
            n, vector<long long>(amount + 1, 0)
        );

        // Amount 0 -> one combination: choose nothing
        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // Using only coins[0]
        for(int target = 0; target <= amount; target++) {
            if(target % coins[0] == 0) {
                dp[0][target] = 1;
            }
        }

        for(int ind = 1; ind < n; ind++) {

            for(int target = 0; target <= amount; target++) {

                long long notTake = dp[ind - 1][target];

                long long take = 0;

                if(coins[ind] <= target) {
                    take = dp[ind][target - coins[ind]];
                }

                // Prevent overflow and values larger than needed
                if(take > LIMIT - notTake)
                    dp[ind][target] = LIMIT;
                else
                    dp[ind][target] = take + notTake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};
