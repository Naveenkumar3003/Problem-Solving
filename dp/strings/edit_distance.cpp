class Solution {
  public:
    /*int dist(int i,int j,string &s1,string &s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(s1[i]==s2[j]) return dist(i-1,j-1,s1,s2);
        else{
            int ins=1+dist(i,j-1,s1,s2);
            int del=1+dist(i-1,j,s1,s2);
            int rep=1+dist(i-1,j-1,s1,s2);
            return min(ins,min(del,rep));
        }
    }
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.length(),m=s2.length();
        return dist(n-1,m-1,s1,s2);
    }*/
    
    /*int dist(int i,int j,string &s1,string &s2,
                vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=dist(i-1,j-1,s1,s2,dp);
        else{
            int ins=1+dist(i,j-1,s1,s2,dp);
            int del=1+dist(i-1,j,s1,s2,dp);
            int rep=1+dist(i-1,j-1,s1,s2,dp);
            return dp[i][j]=min(ins,min(del,rep));
        }
    }
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dist(n-1,m-1,s1,s2,dp);
    }*/
    
    int editDistance(string& s1, string& s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int ins=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];
                    dp[i][j]=min(ins,min(del,rep));
                }
            }
        }
        return dp[n][m];
    }
};
