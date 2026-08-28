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
    int spanningTree(int V, vector<vector<int>>& edges) {
        DSU ds(V);
        sort(edges.begin(),edges.end(),[](vector<int> &a,
                vector<int> &b){
                    return a[2]<b[2];
                }
        );
        int mstWt=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(ds.find(u)!=ds.find(v)){
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};
