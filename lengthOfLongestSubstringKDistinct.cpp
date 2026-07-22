class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length()==0 || k==0) return 0;
        int i=0,j=0;
        int n=s.length(),left=0,maxLen=0;
        unordered_map<char,int> mpp;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            while(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};
