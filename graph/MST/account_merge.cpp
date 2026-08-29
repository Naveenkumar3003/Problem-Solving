class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:

    // Constructor
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // Initially, every element is its own set
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // FIND with Path Compression
    int find(int x) {

        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // UNION by Size
    void unionBySize(int u, int v) {

        int rootU = find(u);
        int rootV = find(v);

        // Already in the same set
        if (rootU == rootV)
            return;

        // Attach smaller set to larger set
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        }
        else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }

    // Check whether two elements belong to same set
    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
  public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        int n=arr.size();
        unordered_map<string,int> nodemail;
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<arr[i].size();j++){
                string mail=arr[i][j];
                if(nodemail.find(mail)==nodemail.end()){
                    nodemail[mail]=i;
                }
                else{
                    ds.unionBySize(i,nodemail[mail]);
                }
            }
        }
        vector<vector<string>> mergedmails(n);
        for(auto it:nodemail){
            string mail=it.first;
            int node=ds.find(it.second);
            mergedmails[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedmails[i].size()==0) continue;
            sort(mergedmails[i].begin(),mergedmails[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for (auto mail : mergedmails[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }
        return ans;
    }
};
