#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:

    // Constructor
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initially, every element is its own parent
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // FIND operation with Path Compression
    int find(int x) {

        // x is the representative
        if (parent[x] == x)
            return x;

        // Path compression
        return parent[x] = find(parent[x]);
    }

    // UNION operation using Rank
    void unionByRank(int u, int v) {

        int rootU = find(u);
        int rootV = find(v);

        // Already in the same set
        if (rootU == rootV)
            return;

        // Attach smaller rank tree under larger rank tree
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        }
        else {
            // Same rank
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    // Optional: Check if two elements belong to same set
    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }

    // Optional: Print parent array
    void printParent(int n) {
        for (int i = 1; i <= n; i++) {
            cout << "Element " << i
                 << " -> Parent " << parent[i] << endl;
        }
    }
};

int main() {

    DSU dsu(7);

    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);

    dsu.unionByRank(4, 5);
    dsu.unionByRank(6, 7);

    dsu.unionByRank(5, 6);

    cout << "Representative of 3: "
         << dsu.find(3) << endl;

    cout << "Representative of 7: "
         << dsu.find(7) << endl;

    cout << "Are 3 and 7 in the same set? "
         << (dsu.sameSet(3, 7) ? "Yes" : "No") << endl;

    dsu.unionByRank(3, 7);

    cout << "After union(3, 7):" << endl;

    cout << "Representative of 3: "
         << dsu.find(3) << endl;

    cout << "Representative of 7: "
         << dsu.find(7) << endl;

    cout << "Are 3 and 7 in the same set? "
         << (dsu.sameSet(3, 7) ? "Yes" : "No") << endl;

    return 0;
}
