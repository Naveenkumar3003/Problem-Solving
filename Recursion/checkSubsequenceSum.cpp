class Solution {
private:
    bool func(int ind, int sum, vector<int> &nums) {
        // Target achieved
        if (sum == 0) return true;

        // Out of bounds or sum became negative
        if (sum < 0 || ind == nums.size()) return false;

        // Include current element OR exclude it
        return func(ind + 1, sum - nums[ind], nums) ||
               func(ind + 1, sum, nums);
    }

public:
    bool isSubsequenceWithTargetSumPresent(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};
