class Solution {
  public:
    void func(int sum,int ind,int n,vector<int>& arr,vector<int> &ans){
        if(ind==n) {
            ans.push_back(sum);
            return ;
        }
        // pick the current element
        func(sum+arr[ind],ind+1,n,arr,ans);
        
        // Not pick the current element
        func(sum,ind+1,n,arr,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        sort(arr.begin(),arr.end());
        func(0,0,arr.size(),arr,ans);
        return ans;
    }
};
