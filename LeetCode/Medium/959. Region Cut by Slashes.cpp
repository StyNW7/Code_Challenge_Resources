// Link: https://leetcode.com/problems/regions-cut-by-slashes/description/

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UnionFind uf(4 * n * n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 4 * (i * n + j);
                char c = grid[i][j];

                if (c == '/') {
                    uf.unionSet(base + 0, base + 3);
                    uf.unionSet(base + 1, base + 2);
                } else if (c == '\\') {
                    uf.unionSet(base + 0, base + 1);
                    uf.unionSet(base + 2, base + 3);
                } else {
                    uf.unionSet(base + 0, base + 1);
                    uf.unionSet(base + 1, base + 2);
                    uf.unionSet(base + 2, base + 3);
                }

                // Connect right neighbor
                if (j + 1 < n) {
                    uf.unionSet(base + 1, 4 * (i * n + (j + 1)) + 3);
                }
                // Connect bottom neighbor
                if (i + 1 < n) {
                    uf.unionSet(base + 2, 4 * ((i + 1) * n + j) + 0);
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < 4 * n * n; ++i) {
            if (uf.find(i) == i) {
                regions++;
            }
        }
        return regions;
    }
};
