class Solution {
  public:
    //Recusion
    // int lcshelper(string &s1,string &s2,int i,int j){
    //     if(i==s1.length() || j==s2.length()) return 0;
        
    //     if(s1[i]==s2[j]) return 1+lcshelper(s1,s2,i+1,j+1);
    //     else return max(lcshelper(s1,s2,i,j+1),lcshelper(s1,s2,i+1,j));
    // }
    // int lcs(string &s1, string &s2) {
    //     return lcshelper(s1,s2,0,0);
    // }
    
    // Memoization
    // int lcshelper(string &s1,string &s2,int i,int j,vector<vector<int>>& dp){
    //     if(i==s1.length() || j==s2.length()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j]) return dp[i][j]=1+lcshelper(s1,s2,i+1,j+1,dp);
    //     else return dp[i][j]=max(lcshelper(s1,s2,i,j+1,dp),lcshelper(s1,s2,i+1,j,dp));
    // }
    // int lcs(string &s1, string &s2) {
    //     vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),-1));
    //     return lcshelper(s1,s2,0,0,dp);
    // }
    
    
    // Tabulation
    int lcs(string &s1, string &s2) {
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    
            }
        }
        return dp[s1.length()][s2.length()];
    }
    
};
