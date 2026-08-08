class Solution {
public:

    /*int solve(int ind, vector<int>& val,
              vector<int>& wt, int W) {
        // Only item 0 is available
        if(ind == 0) {
            if(wt[0] <= W) {
                return (W / wt[0]) * val[0];
            }
            return 0;
        }
        // Don't take current item
        int nottake = solve(ind - 1, val, wt, W);
        // Take current item
        int take = 0;
        if(wt[ind] <= W) {
            take = val[ind] +
                   solve(ind, val, wt,
                         W - wt[ind]);
        }
        return max(take, nottake);
    }

    int knapSack(vector<int>& val,
                 vector<int>& wt,int W) {

        return solve(wt.size() - 1, val, wt, W);
    }*/
    
    /*int solve(int ind, vector<int>& val,
              vector<int>& wt, int W,
              vector<vector<int>>& dp) {
        // Base case
        if(ind == 0) {
            return (W / wt[0]) * val[0];
        }
        if(dp[ind][W] != -1)
            return dp[ind][W];
        // Don't take
        int nottake = solve(ind - 1, val, wt, W, dp);
        // Take
        int take = 0;
        if(wt[ind] <= W) {
            take = val[ind] +
                   solve(ind, val, wt,
                         W - wt[ind], dp);
        }
        return dp[ind][W] = max(take, nottake);
    }
    int knapSack(vector<int>& val,
                 vector<int>& wt,int W) {
        int n = wt.size();
        vector<vector<int>> dp(
            n, vector<int>(W + 1, -1)
        );
        return solve(n - 1, val, wt, W, dp);
    }*/
    
    int knapSack(vector<int>& val,
                 vector<int>& wt,int W) {

        int n = wt.size();

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case
        // Only item 0 is available.
        // We can take it multiple times.
        for(int capacity = 0;capacity <= W;capacity++) {
            dp[0][capacity] = (capacity / wt[0]) * val[0];
        }

        // Fill table
        for(int ind = 1; ind < n; ind++) {
            for(int capacity = 0;capacity <= W;capacity++) {
                // Don't take
                int nottake =
                    dp[ind - 1][capacity];
                // Take
                int take = 0;
                if(wt[ind] <= capacity) {
                    take = val[ind] + dp[ind][capacity - wt[ind]];
                }
                dp[ind][capacity] = max(take, nottake);
            }
        }

        return dp[n - 1][W];
    }
};
