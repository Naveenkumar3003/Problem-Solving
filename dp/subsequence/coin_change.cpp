class Solution {
public:
    // Recursion
    /*int solve(int ind,int amount,vector<int> &coins){
        if(amount==0) return 0;
        if(ind==0){
            if(amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        } 
        int nottake=solve(ind-1,amount,coins);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+solve(ind,amount-coins[ind],coins);
        }
        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(coins.size()-1,amount,coins);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }*/
    // Memoization
    /*int solve(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(ind==0){
            if(amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake=solve(ind-1,amount,coins,dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+solve(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }*/

    // Tabulation
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));
        for(int i = 0; i < coins.size(); i++) {
            dp[i][0] = 0;
        }
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)
                dp[0][target]=target/coins[0];
        }

        for(int ind=1;ind<coins.size();ind++){
            for(int target=0;target<=amount;target++){
                int nottake=dp[ind-1][target];
                int take=1e9;
                if(coins[ind]<=target){
                    take=1+dp[ind][target-coins[ind]];
                }
                dp[ind][target]=min(take,nottake);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};
