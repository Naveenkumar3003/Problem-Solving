class Solution {
public:
        // Same as subset sum
        // here we will find the sum first and if it is divided by then we can take that as target and check whether the target is present in the array or not
        // if the totalsum is odd then we can't able divide by two so there will no subset exist
    // Recursion
    // bool solve(int ind,int sum,vector<int> &nums){
    //     if(sum==0) return 0;
    //     if(ind==0) return nums[ind]==sum;

    //     bool nottake=solve(ind-1,sum,nums);
    //     bool take=false;
    //     if(nums[ind]<=sum){
    //         take=solve(ind-1,sum-nums[ind],nums);
    //     }
    //     return nottake||take;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //     }
    //     if(sum%2==1) return false;
    //     else{
    //         int k=sum/2;
    //         return solve(nums.size()-1,k,nums);
    //     }
    // }

    // Memoization
    // bool solve(int ind,int sum,vector<int> &nums,vector<vector<int>> &dp){
    //     if(sum==0) return 0;
    //     if(ind==0) return nums[ind]==sum;
    //     if(dp[ind][sum]!=-1) return dp[ind][sum];
    //     bool nottake=solve(ind-1,sum,nums,dp);
    //     bool take=false;
    //     if(nums[ind]<=sum){
    //         take=solve(ind-1,sum-nums[ind],nums,dp);
    //     }
    //     return dp[ind][sum]=nottake||take;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //     }
    //     if(sum%2==1) return false;
    //     else{
    //         int k=sum/2;
    //         vector<vector<int>> dp(nums.size(),vector<int> (k+1,-1));
    //         return solve(nums.size()-1,k,nums,dp);
    //     }
    // }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        else{
            int n=nums.size();
            int k=sum/2;
            vector<vector<bool>> dp(nums.size(),vector<bool> (k+1,false));
            for(int i=0;i<nums.size();i++){
                dp[i][0]=true;
            }
            if(nums[0]<=k) dp[0][nums[0]]=true;
            for(int i=1;i<n;i++){
                for(int sum=0;sum<=k;sum++){
                    bool nottake=dp[i-1][sum];
                    bool take=false;
                    if(nums[i]<=sum){
                        take=dp[i-1][sum-nums[i]];
                    }
                    dp[i][sum]=take||nottake;
                }
            }
            return dp[n-1][k];
        }
    }
};
