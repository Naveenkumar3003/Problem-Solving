class Solution {
  public:
    /*int liseq(int ind,int prev_ind,vector<int> &arr){
        if(ind==arr.size()) return 0;
        int nottake=liseq(ind+1,prev_ind,arr);
        int take=0;
        if(prev_ind==-1 || arr[ind]>arr[prev_ind]) {
            take=1+liseq(ind+1,ind,arr);
        }
        return max(nottake,take);
    }
    int lis(vector<int>& arr) {
        return liseq(0,-1,arr);
    }*/
    
    
    /*int liseq(int ind,int prev_ind,vector<int> &arr,
                vector<vector<int>> &dp){
        if(ind==arr.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int nottake=liseq(ind+1,prev_ind,arr,dp);
        int take=0;
        if(prev_ind==-1 || arr[ind]>arr[prev_ind]) {
            take=1+liseq(ind+1,ind,arr,dp);
        }
        return dp[ind][prev_ind+1]=max(nottake,take);
    }
    int lis(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size()+1,-1));
        return liseq(0,-1,arr,dp);
    }*/
    
    /*int lis(vector<int>& arr) {
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
        return dp[0][0];
    }*/
    
    /*
    int lis(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
    */
    int lowerBound(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=n;
        int low=0,high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int lis(vector<int>& arr) {
        vector<int> temp;
        for(int i=0;i<arr.size();i++){
            int pos=lowerBound(temp,arr[i]);
            if(pos==temp.size()){
                temp.push_back(arr[i]);
            }
            else{
                temp[pos]=arr[i];
            }
        }
        return temp.size();
    }
};
