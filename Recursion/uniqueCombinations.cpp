class Solution {
  public:
    void findComb(int ind,int target,vector<int> &arr,vector<int> &curr,
        vector<vector<int>>& ans){
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            curr.push_back(arr[i]);
            findComb(i+1,target-arr[i],arr,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(),arr.end());
        findComb(0,target,arr,curr,ans);
        return ans;
    }
};
