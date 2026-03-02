class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //use a map to store all relations a variable has
        //for each query in queries, traverse thru the relations to find the required relation, the weights multiplied is the answer for that query
        //store answer for all queries in a array.
        //SC:O(n+m)
        //TC:O(n*m)
        unordered_map<string,vector<pair<string,double>>>adjList;
        int n=equations.size();
        int m=queries.size();
        vector<double>ans(m,-1.0);
        //TC:O(N)
        for (int i=0;i<n;i++){
            adjList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjList[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        //TC:O(m*n)
        for (int i=0;i<m;i++){
            if (adjList.find(queries[i][0])==adjList.end()) continue;
            if (queries[i][0]==queries[i][1]) {
                ans[i]=1;
                continue;
            }
            unordered_set<string>st;
            queue<pair<string,double>>q;
            q.push({queries[i][0],1.0});
            st.insert(queries[i][0]);
            while(!q.empty()){
                auto [var,wt]=q.front();
                q.pop();
                if (var==queries[i][1]) {
                    ans[i]=wt;
                    break;
                }
                vector<pair<string,double>>&neighbors=adjList[var];
                for (auto &it:neighbors){
                    if (st.find(it.first)!=st.end()) continue;
                    q.push({it.first,wt*it.second});
                    st.insert(it.first);
                }
            }
        }
        return ans;

    }
};