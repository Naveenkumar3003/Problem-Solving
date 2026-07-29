class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0,maxFreq=0,n=s.length();
        unordered_map<char,int> mpp;
       for(int r=0;r<n;r++){
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]); 
            // If window is invalid, shrink it 
            while((r - l + 1) - maxFreq > k){ 
                mpp[s[l]]--; 
                l++; 
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};
