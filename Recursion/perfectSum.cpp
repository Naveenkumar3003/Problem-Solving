class Solution {
  public:
    int solve(int ind,int sum,int target,vector<int> &arr){
        if(ind==arr.size()){
            return (sum==target);
        }
        
        return solve(ind+1,sum+arr[ind],target,arr)+solve(ind+1,sum,target,arr);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int sum=0;
        return solve(0,sum,target,arr);
    }
};
