class Solution {
public:
    void comb(int ind,string digits,string curr,vector<string> &ans,vector<string> &mapping){
        if(ind>=digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit=digits[ind]-'0';
        string val=mapping[digit];
        for(int i=0;i<val.length();i++){
            curr.push_back(val[i]);
            comb(ind+1,digits,curr,ans,mapping);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string curr="";
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        comb(0,digits,curr,ans,mapping);
        return ans;
    }
};
