class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0,n=s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        unordered_map<char,int> mpp;
        while(r<n){
            if(mpp[s[r]]==0){
                mpp[s[r]]=1;
                r++;
            }
            else{
                maxLen=max(maxLen,r-l);
                mpp[s[l]]=0;
                l++;
            }
        }
        maxLen = max(maxLen, r-l);
        return maxLen;

    }
};
