// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false; // u and v are already in the same set

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    int connectedComponents() {
        int count = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
        UnionFind alice(n + 1), bob(n + 1);
        int edgesAdded = 0;

        // Step 1: Add type 3 edges
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2])) {
                    bob.unite(edge[1], edge[2]);
                    edgesAdded++;
                }
            }
        }

        // Step 2: Add type 1 edges for Alice and type 2 edges for Bob
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesAdded++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesAdded++;
                }
            }
        }

        // Step 3: Check if both Alice and Bob can fully traverse the graph
        if (alice.connectedComponents() != 2 || bob.connectedComponents() != 2) {
            return -1; // not fully connected
        }

        return edges.size() - edgesAdded;
    }
};
