class Solution {
  public:
    bool func(int ind, int sum, std::vector<int> &nums) {
        // Base case: if all elements are processed, check if sum is 0
        if (ind == nums.size()) {
            return sum == 0;
        }
        // Recursive call: include the current element in the subsequence
        // or exclude the current element from the subsequence
        return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
    }

    public:
        // This method initiates the recursive process
        bool checkSubsequenceSum(std::vector<int>& nums, int target) {
            return func(0, target, nums); // Start the recursive process
        }
};
