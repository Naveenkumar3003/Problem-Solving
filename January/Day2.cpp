//961. N-Repeated Element in Size 2N Array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for(int x:nums){
            if(!s.insert(x).second) return x;
        }
        return -1;
    }
};
