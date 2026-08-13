// https://www.hackerrank.com/contests/2024-2025-2/challenges/clusterstask/problem

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        rank.resize(n, 0);
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

    DSU dsu(n);

    int components = n;

    vector<int> maxEdge(n, 0);

    for (const Edge& edge : edges) {
        if (components == k)
            break;

        if (dsu.unite(edge.u, edge.v)) {

            components--;

            int root = dsu.find(edge.u);

            maxEdge[root] = max(maxEdge[root], edge.weight);
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            answer.push_back(maxEdge[i]);
        }
    }

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++) {
        if (i > 0)
            cout << " ";

        cout << answer[i];
    }

    cout << endl;

    return 0;
}
