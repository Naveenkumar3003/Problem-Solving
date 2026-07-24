class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0],minProd=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(minProd,maxProd);
            minProd=min(nums[i],minProd*nums[i]);
            maxProd=max(nums[i],maxProd*nums[i]);
            ans=max(ans,maxProd);
        }
        return ans;
    }
};
