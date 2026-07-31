class Solution {
public:
    void solve(int open,int close,int n,string &curr,vector<string> &ans){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        //we can push ( for n times
        if(open<n){
            curr.push_back('(');
            solve(open+1,close,n,curr,ans);
            curr.pop_back();
        }
        //we can push ) for already opened times
        if(close<open){
            curr.push_back(')');
            solve(open,close+1,n,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        solve(0,0,n,curr,ans);
        return ans;
    }
};
