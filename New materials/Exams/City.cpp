#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(
        int n,
        int m,
        int S,
        int X,
        vector<vector<pair<int, int>>>& graph
    ) {
        const long long INF = 1e18;

        vector<long long> dist(n + 1, INF);
        vector<int> parent(n + 1, -1);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            long long currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentDist != dist[u])
                continue;

            for (auto edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;

                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[X] == INF) {
            return {};
        }

        vector<int> path;

        int current = X;

        while (current != -1) {
            path.push_back(current);

            if (current == S)
                break;

            current = parent[current];
        }

        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
    int N, M, S, X;
    cin >> N >> M >> S >> X;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, time;
        cin >> a >> b >> time;

        graph[a].push_back({b, time});
        graph[b].push_back({a, time});
    }

    Solution solution;

    vector<int> path = solution.shortestPath(
        N, M, S, X, graph
    );

    if (path.empty()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];

        if (i + 1 < path.size())
            cout << " ";
    }

    cout << endl;

    return 0;
}
