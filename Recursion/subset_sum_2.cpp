class Solution {
  public:
    void func(int start,vector<int>& arr, vector<int>& curr,vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=start;i<arr.size();i++){
            if(i>start && arr[i]==arr[i-1]) continue;
            curr.push_back(arr[i]);
            func(i+1,arr,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> curr;
        func(0,arr,curr,ans);
        return ans;
    }
};
