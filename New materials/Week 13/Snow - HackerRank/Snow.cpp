#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
        }

        cout << 0;
        return 0;
    }

    DSU dsu(n);

    int components = n;
    int answer = -1;

    for (int hour = 1; hour <= m; hour++) {
        int u, v;
        cin >> u >> v;

        if (dsu.unite(u, v)) {
            components--;
        }

        if (components == 1 && answer == -1) {
            answer = hour;
        }
    }

    cout << answer;

    return 0;
}
