class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> freq;
        for(int num:arr){
            freq[num]++;
        }
        unordered_set<int> st;
        for(auto iter:freq){
            if(st.count(iter.second)) return false;
            st.insert(iter.second);
        }
        return true;
    }
};