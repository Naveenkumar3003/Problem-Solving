class Solution {
  public:
    bool isPal(string &temp){
        int i=0,j=temp.length()-1;
        while(i<=j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // Recursion
    // int f(int ind,int n,string &s){
    //     if(ind == n) return 0;
    //     string temp="";
    //     int cnt=0,minpar=INT_MAX;
    //     for(int j=ind;j<n;j++){
    //         temp+=s[j];
    //         if(isPal(temp)){
    //             cnt=1+f(j+1,n,s);
    //             minpar=min(cnt,minpar);
    //         }
    //     }
    //     return minpar;
    // }
    // int palPartition(string &s) {
    //     // code here
    //     int n=s.length();
    //     return f(0,n,s)-1;
    // }
    
    // Memoization
    // int f(int ind,int n,string &s,vector<int> &dp){
    //     if(ind == n) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     string temp="";
    //     int cnt=0,minpar=INT_MAX;
    //     for(int j=ind;j<n;j++){
    //         temp+=s[j];
    //         if(isPal(temp)){
    //             cnt=1+f(j+1,n,s,dp);
    //             minpar=min(cnt,minpar);
    //         }
    //     }
    //     return dp[ind]=minpar;
    // }
    // int palPartition(string &s) {
    //     // code here
    //     int n=s.length();
    //     vector<int> dp(n,-1);
    //     return f(0,n,s,dp)-1;
    // }
    
    // Tabulation
    int palPartition(string &s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[n]=0;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            int minpar=INT_MAX;
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isPal(temp)){
                    cnt=1+dp[j+1];
                    minpar=min(cnt,minpar);
                }
            }
            dp[i]=minpar;
        }
        return dp[0]-1;
    }
};
