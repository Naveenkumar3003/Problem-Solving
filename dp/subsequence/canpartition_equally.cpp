class Solution {
  public:
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
    bool equalPartition(vector<int>& arr) {
        // Same as subset sum
        // here we will find the sum first and if it is divided by then we can take that as target and check whether the target is present in the array or not
        // if the totalsum is odd then we can't able divide by two so there will no subset exist
        int totalsum=0;
        for(int i=0;i<arr.size();i++){
            totalsum+=arr[i];
        }
        ;
        if(totalsum%2==1) return false;
        else{
            int target=totalsum/2;
            return isSubsetSum(arr,target);
        }
    }
};
