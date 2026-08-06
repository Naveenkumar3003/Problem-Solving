class Solution {
  public:
    // Recursion
    // bool subsum(int n,int sum,vector<int>& arr){
    //     if(sum==0) return true;
    //     if(n==0) return sum==arr[n];
    //     bool take=false;
    //     if(arr[n]<=sum){
    //         take=subsum(n-1,sum-arr[n],arr);
    //     }
    //     bool nottake=subsum(n-1,sum,arr);
        
    //     return take||nottake;
    // }
    // bool isSubsetSum(vector<int>& arr, int sum) {
    //     // code here
    //     return subsum(arr.size(),sum,arr);
    // }
    
    // Memoization
    // bool subsum(int n,int sum,vector<int>& arr,vector<vector<int>>& dp){
    //     if(sum==0) return true;
    //     if(n<0) return false;
    //     if(n==0) return sum==arr[n];
    //     if(dp[n][sum]!=-1) return dp[n][sum];
    //     bool take=false;
    //     if(arr[n]<=sum){
    //         take=subsum(n-1,sum-arr[n],arr,dp);
    //     }
    //     bool nottake=subsum(n-1,sum,arr,dp);
        
    //     return dp[n][sum]=take||nottake;
    // }
    // bool isSubsetSum(vector<int>& arr, int sum) {
    //     vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
    //     return subsum(arr.size()-1,sum,arr,dp);
    // }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Sum = 0 is always possible
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // First element
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= sum; j++) {

                bool notTake = dp[i - 1][j];

                bool take = false;

                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }
};
