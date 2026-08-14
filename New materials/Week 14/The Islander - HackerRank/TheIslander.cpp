#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges;
        map<int, int> id;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            edges.push_back({u, v});

            if (id.find(u) == id.end()) {
                int newId = id.size();
                id[u] = newId;
            }

            if (id.find(v) == id.end()) {
                int newId = id.size();
                id[v] = newId;
            }
        }

        if (n == 1) {
            cout << "ecycle\n";
            continue;
        }

        if (id.size() != n) {
            cout << "none\n";
            continue;
        }

        int vertices = id.size();

        vector<vector<int>> graph(vertices);
        vector<int> degree(vertices, 0);

        for (auto edge : edges) {
            int u = id[edge.first];
            int v = id[edge.second];

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        vector<bool> visited(vertices, false);

        stack<int> st;
        st.push(0);
        visited[0] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    st.push(v);
                }
            }
        }

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                cout << "none\n";
                goto next_test;
            }
        }

        {
            int odd = 0;

            for (int i = 0; i < vertices; i++) {
                if (degree[i] % 2 != 0) {
                    odd++;
                }
            }

            if (odd == 0) {
                cout << "ecycle\n";
            }
            else if (odd == 2) {
                cout << "epath\n";
            }
            else {
                cout << "none\n";
            }
        }

        next_test:;
    }

    return 0;
}
