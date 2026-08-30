class Solution {
public:
    /*int disSeq(int i,int j,string &s, string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=disSeq(i-1,j-1,s,t,dp)+disSeq(i-1,j,s,t,dp);
        else return dp[i][j]=disSeq(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return disSeq(s.length()-1,t.length()-1,s,t,dp);
    }*/
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long >(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        // for(int j=0;j<=m;j++){
        //     dp[0][j]=0;             This is not needed because while declaring itself we are initializing
        // }                            and it will also make dp[0][0] as 0 which was declared 1 in previous case
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])  dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else  dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
