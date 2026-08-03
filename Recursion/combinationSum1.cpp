class Solution {
  public:
    void findComb(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,
        vector<int>& curr){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return ;
        }
        // if(target==0) ans.push_back(curr); this line will give duplicate combinations so dont use this
        if(arr[ind]<=target){
            curr.push_back(arr[ind]);
            findComb(ind,target-arr[ind],arr,ans,curr);
            curr.pop_back();
        }
        findComb(ind+1,target,arr,ans,curr);
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        int currsum=0;
        findComb(0,target,arr,ans,curr);
        return ans;
    }
};
