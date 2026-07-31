class Solution {
  public:
    // Recursion
    // int helper(int i,int n,vector<int> height){
    //     if(i==n-1){
    //         return 0;
    //     }
    //     int take1=abs(height[i]-height[i+1])+helper(i+1,n,height);
    //     int take2=INT_MAX;
    //     if(i+2<n){
    //         take2=abs(height[i]-height[i+1])+helper(i+2,n,height);
    //     }
    //     return min(take1,take2);
    // }
    // int minCost(vector<int>& height) {
    //     // Code here
    //     int n=height.size();
    //     return helper(0,n,height);
    // }
    
    // Memoization
    // int helper(int i,int n,vector<int> height,vector<int> &dp){
    //     if(i==n-1){
    //         return 0;
    //     }
    //     if(dp[i]!=-1) return dp[i];
    //     int take1=abs(height[i]-height[i+1])+helper(i+1,n,height,dp);
    //     int take2=INT_MAX;
    //     if(i+2<n){
    //         take2=abs(height[i]-height[i+2])+helper(i+2,n,height,dp);
    //     }
    //     return dp[i]=min(take1,take2);
    // }
    // int minCost(vector<int>& height) {
    //     // Code here
    //     int n=height.size();
    //     vector<int> dp(n,-1);
    //     return helper(0,n,height,dp);
    // }
    
    // Tabulation
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n,0);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int take1=abs(height[i]-height[i+1])+dp[i+1];
            int take2=INT_MAX;
            if(i+2<n){
                take2=abs(height[i]-height[i+2])+dp[i+2];
            }
            dp[i]=min(take1,take2);
        }
        return dp[0];
    }
};
