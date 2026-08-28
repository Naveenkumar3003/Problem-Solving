class DSU {

public:
    vector<int> parent;
    vector<int> size;

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
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        DSU ds(V);
        int extra=0;
        for(auto edge: edges){
            if(ds.sameSet(edge[0],edge[1])){
                extra++;
            }
            else{
                ds.unionBySize(edge[0],edge[1]);
            }
        }
        int comp=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i) comp++;
        }
        
        int ans=comp-1;
        if(extra>=ans) return ans;
        else return -1;
    }
};
