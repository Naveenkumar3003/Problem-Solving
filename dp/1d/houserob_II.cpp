//Here we consider first and last also as the adjacent houses
class Solution {
    int helper(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin(), nums.end() - 1); // Houses 0 to n-2
        vector<int> temp2(nums.begin() + 1, nums.end()); // Houses 1 to n-1

        return max(helper(temp1), helper(temp2));
    }
};
