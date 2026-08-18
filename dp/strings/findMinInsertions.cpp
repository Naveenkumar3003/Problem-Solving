class Solution {
  public:
      int lcs(string &s1,string &s2){
          int n=s1.length(),m=s2.length();
          vector<vector<int>> dp(n+1,vector<int> (m+1,0));
          for(int i=1;i<=n;i++){
              for(int j=1;j<=m;j++){
                  if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                  else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
          return dp[n][m];
      }
      int longestPalinSubseq(string &s) {
          // code here
          string s2="";
          for (int i = s.length() - 1; i >= 0; i--) {
              s2 += s[i];                 // Manual reverse
          }
          //reverse(s2.begin(),s2.end());
          return lcs(s,s2);
      }
    int findMinInsertions(string &s) {
        // code here
        int n=s.length();
        int len=longestPalinSubseq(s);
        return n-len;
    }
};
