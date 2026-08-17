// https://www.hackerrank.com/contests/2024-2025-2/challenges/treevalidator/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

bool hasCycle(long long current, long long parent, vector<vector<long long>>& graph, vector<bool>& visited) {

    visited[current] = true;

    for(long long neighbour : graph[current]) {

        if(!visited[neighbour]) {

            if(hasCycle(neighbour, current, graph, visited)) {
                return true;
            }
        }
        else if(neighbour != parent) {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long queries;
    cin >> queries;

    while(queries--) {

        long long N, M;
        cin >> N >> M;

        vector<vector<long long>> graph(N);

        for(long long i = 0; i < M; ++i) {
            long long u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(N, false);

        if(N == 0) {
            cout << 0 << '\n';
            continue;
        }

        if(hasCycle(0, -1, graph, visited)) {
            cout << 0 << '\n';
            continue;
        }

        bool connected = true;

        for(long long i = 0; i < N; ++i) {

            if(!visited[i]) {
                connected = false;
                break;
            }
        }

        if(connected) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
