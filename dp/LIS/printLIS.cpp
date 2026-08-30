class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=n-1;prev_ind>=-1;prev_ind--){
                int nottake=dp[ind+1][prev_ind+1];
                int take=0;
                if(prev_ind==-1 || arr[ind]>arr[prev_ind]) {
                    take=1+dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1]=max(nottake,take);
            }
        }
        vector<int> ans;
        int ind=0,prev_ind=-1;
        while(ind<n){
            int nottake=dp[ind+1][prev_ind+1];
            int take=-1;
            if(prev_ind==-1 || arr[ind]>arr[prev_ind]) {
                    take=1+dp[ind+1][ind+1];
            }
            
            if(take>=nottake){
                ans.push_back(arr[ind]);
                prev_ind=ind;
            }
            ind++;
        }
        return ans;
    }
};
