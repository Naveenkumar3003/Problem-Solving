class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> dp(n+1,0);
        // int offset=1;
        // for(int i=1;i<=n;i++){
        //     if(offset*2==i) offset=i;
        //     dp[i]=1+dp[i-offset];
        // }
        // return dp;
        vector<int> cnt(n+1,0);
        for(int i=0;i<=n;i++){
            int n=i;
            while(n){
                cnt[i]+=n%2;
                n=n/2;
            }
        }
        return cnt;
    }
};
