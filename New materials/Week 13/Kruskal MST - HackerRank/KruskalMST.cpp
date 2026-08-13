// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

class DSU {
private:
    vector<int> parent, rank_;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank_.resize(n + 1, 0);

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

        if (rank_[a] < rank_[b]) {
            parent[a] = b;
        }
        else if (rank_[a] > rank_[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank_[a]++;
        }

        return true;
    }
};

int kruskals(int g_nodes,
             vector<int> g_from,
             vector<int> g_to,
             vector<int> g_weight) {

    vector<Edge> edges;

    for (int i = 0; i < g_from.size(); i++) {
        edges.push_back({g_from[i], g_to[i], g_weight[i]});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            if (a.w != b.w) {
                return a.w < b.w;
            }

            return (a.u + a.v) < (b.u + b.v);
        });

    DSU dsu(g_nodes);

    int totalWeight = 0;
    int usedEdges = 0;

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            totalWeight += edge.w;
            usedEdges++;

            if (usedEdges == g_nodes - 1) {
                break;
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> from(m), to(m), weight(m);

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
    }

    cout << kruskals(n, from, to, weight);

    return 0;
}
