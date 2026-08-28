#include <bits/stdc++.h>
using namespace std;

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

int main() {

    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);

    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);

    dsu.unionBySize(5, 6);

    cout << "Representative of 3: "
         << dsu.find(3) << endl;

    cout << "Representative of 7: "
         << dsu.find(7) << endl;

    cout << "Are 3 and 7 in the same set? "
         << (dsu.sameSet(3, 7) ? "Yes" : "No") << endl;

    dsu.unionBySize(3, 7);

    cout << "After union(3, 7):" << endl;

    cout << "Representative of 3: "
         << dsu.find(3) << endl;

    cout << "Representative of 7: "
         << dsu.find(7) << endl;

    return 0;
}
