class Solution {
  public:
    /*bool match(int i,int j,string &s1, string &s2,vector<vector<int>> &dp){
        if(i<0 && j<0) return true; // in 1 based indexing condition will be i==0 j==0
        if(i<0 && j>=0) return false;  // i==0 j>0
        if(j<0 && i>=0){ // j==0 i>0
            for(int k=0;k<=i;k++){
                if(s1[k]!='*') return false;  // s1[k-1]
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(s1[i]==s2[j] || s1[i]=='?') return dp[i][j]=match(i-1,j-1,s1,s2,dp); // s1[i-1]==s2[j-1] || s1[i-1]
        if(s1[i]=='*') return dp[i][j]=match(i-1,j,s1,s2,dp) || match(i,j-1,s1,s2,dp); // s1[i-1]
        return dp[i][j]=false;
    }
    bool wildCard(string &txt, string &pat) {
        int n=pat.length(),m=txt.length();
        vector<vector<int>> dp(n,vector<int>(m,-1)); n+1, m+1
        return match(n-1,m-1,pat,txt,dp); n m 
    }*/
    bool wildCard(string &s2, string &s1) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int j=1;j<=m;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int k=1;k<=i;k++){
                if(s1[k-1]!='*') {
                    flag=false;  // s1[k-1]
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1] || s1[i-1]=='?')  dp[i][j]=dp[i-1][j-1]; // s1[i-1]==s2[j-1] || s1[i-1]
                else if(s1[i-1]=='*')  dp[i][j]=dp[i-1][j] || dp[i][j-1]; // s1[i-1]
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};
