class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=n;
        int low=0,high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
