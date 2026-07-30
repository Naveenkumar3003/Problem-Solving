class Solution {
public:
    // Recursion
    // int helper(vector<int> nums,int n){
    //     if(n<0) return 0;
    //     if(n==0) return nums[0];
    //     int pick=nums[n]+helper(nums,n-2);
    //     int notpick=helper(nums,n-1);
    //     return max(pick,notpick);
    // }
    // int rob(vector<int>& nums) {
    //     return helper(nums,nums.size()-1);
    // }

    //Memoization
    // int helper(vector<int> nums,int n,vector<int> &dp){
    //     if(n<0) return 0;
    //     if(n==0) return nums[0];
    //     if(dp[n]!=-1) return dp[n];
    //     int pick=nums[n]+helper(nums,n-2,dp);
    //     int notpick=helper(nums,n-1,dp);
    //     return dp[n]=max(pick,notpick);
    // }
    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size(),-1);
    //     return helper(nums,nums.size()-1,dp);
    // }
    //Tabulation
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=(i>1)?nums[i]+dp[i-2]:nums[i];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
     }
};
