class Solution {
  public:
    int numberofLIS(vector<int>& nums) {
        // Code here
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // Found a longer LIS
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        // inherit the count from previous
                        cnt[i] = cnt[j];
                    }
                    // Found another LIS of same length
                    else if (len[j] + 1 == len[i]) {
                        // increase the count 
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        // Count all LIS having maximum length
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == maxLen) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};
