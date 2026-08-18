class Solution {
  public:
    // Recursion
    // int lcsub(string &s1,string &s2,int i,int j){
    //     if(i==s1.length() || j==s2.length()) return 0;
        
    //     if(s1[i]==s2[j]) return 1+lcsub(s1,s2,i+1,j+1);
    //     else return 0;
    // }
    // int longCommSubstr(string& s1, string& s2) {
    //     int n=s1.length(),m=s2.length(),maxLen=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             maxLen=max(maxLen,lcsub(s1,s2,i,j));
    //         }
    //     }
    //     return maxLen;
    // }
    
    // Memoization
    /*int lcsub(string &s1,string &s2,int i,int j,vector<vector<int>> &dp, int &maxLen){
        if(i==s1.length() || j==s2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if(s1[i]==s2[j]) dp[i][j] = 1 + lcsub(s1, s2, i + 1, j + 1, dp, maxLen);
        else dp[i][j]=0;
        maxLen = max(maxLen, dp[i][j]);
        return dp[i][j];
    }
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.length(),m=s2.length(),maxLen=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                lcsub(s1,s2,i,j,dp,maxLen);
            }
        }
        return maxLen;
    }*/
    
    
    // Tabulation
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.length(),m=s2.length(),maxLen=0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){ 
                    dp[i][j] = 1 + dp [i + 1][ j + 1];
                    maxLen = max(maxLen, dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return maxLen;
    }
    
    
    
    
};
