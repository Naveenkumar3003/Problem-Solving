class Solution {
  public:
  
    // Recursion
    /*int solve(int ind,vector<int> &val,vector<int>&wt,int W){
        if(ind==0){
            if(wt[ind]<=W)
                return val[ind];
            return 0;
        }
        
        int nottake=solve(ind-1,val,wt,W);
        int take=0;
        if(wt[ind]<=W){
            take=val[ind]+solve(ind-1,val,wt,W-wt[ind]);
        }
        return max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        return solve(wt.size()-1,val,wt,W);
    }*/
    
    // Memoization
    /*int solve(int ind,vector<int> &val,vector<int>&wt,int W,
                vector<vector<int>> &dp){
        if(ind==0){
            if(wt[ind]<=W)
                return val[ind];
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int nottake=solve(ind-1,val,wt,W,dp);
        int take=0;
        if(wt[ind]<=W){
            take=val[ind]+solve(ind-1,val,wt,W-wt[ind],dp);
        }
        return dp[ind][W]=max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(wt.size(),vector<int>(W+1,-1));
        return solve(wt.size()-1,val,wt,W,dp);
    }*/
    
    // Tabulation
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(wt.size(),vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++){
            dp[0][i]=val[0];
        }
        
        for(int ind=1;ind<wt.size();ind++){
            for(int capacity=1;capacity<=W;capacity++){
                int nottake=dp[ind-1][capacity];
                int take=0;
                if(wt[ind]<=capacity){
                    take=val[ind]+dp[ind-1][capacity-wt[ind]];
                }
                dp[ind][capacity]=max(take,nottake);
            }
        }
        return dp[wt.size()-1][W];
    }
    
};
