class Solution {
  public:
    // Brute
    // string minWindow(string &s, string &p) {
    //     // code here
    //     int n=s.length();
    //     int m=p.length();
    //     int minLen=INT_MAX,stind=-1;
    //     for(int i=0;i<n;i++){
    //         int hash[256]={0};
    //         int cnt=0;
    //         for(int k=0;k<m;k++){
    //             hash[p[k]]++;
    //         }
    //         for(int j=i;j<n;j++){
    //             if(hash[s[j]]>0) cnt++;             TC- O(n^2)
    //             hash[s[j]]--;
    //             if(cnt==m){
    //                 if(j-i+1<minLen){
    //                     minLen=j-i+1;
    //                     stind=i;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     if(stind==-1) return "";
    //     return s.substr(stind,minLen);
    // }
  // Optimal 
  string minWindow(string &s, string &p) {

        int hash[256] = {0};

        for (char c : p)
            hash[c]++;

        int left = 0;
        int cnt = 0;                  
        int start = -1;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {

            if (hash[s[right]] > 0)
                cnt++;

            hash[s[right]]--;

            while (cnt == p.size()) {

                if (right - left + 1 < minLen) {            //TC - O(2n + m)
                    minLen = right - left + 1;
                    start = left;
                }

                hash[s[left]]++;

                if (hash[s[left]] > 0)
                    cnt--;

                left++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};
