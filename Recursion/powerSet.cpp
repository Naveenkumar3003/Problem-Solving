class Solution {
  public:
    vector<string> powerSet(string s) {
        // code here
        int n=s.length();
        vector<string> ans;
        for(int num = 0; num < (1<<n); num++) {
            string sub = "";
            for(int i = 0; i < n; i++) {
        
                if(num & (1<<i))
                    sub += s[i];
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
