#include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool hasCycle(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& inPath, int current) {
    if (inPath.count(current)) {
        return true;
    }

    if (visited.count(current)) {
        return false;
    }

    visited.insert(current);

    inPath.insert(current);

    for (int adjacent : graph[current]) {
        if (hasCycle(graph, visited, inPath, adjacent)) {
            return true;
        }
    }

    inPath.erase(current);

    return false;
}


int main() {

    int q;
    cin >> q;

    for (int test = 0; test < q; test++) {
        int n, edgesCount;
        cin >> n >> edgesCount;

        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < edgesCount; i++) {
            int from, to, weight;

            cin >> from >> to >> weight;

            graph[from].push_back(to);
        }

        unordered_set<int> visited;
        unordered_set<int> inPath;

        bool hasAnyCycle = false;

        for (int i = 1; i <= n; i++) {
            if (!visited.count(i)) {

                if (hasCycle(graph, visited, inPath, i)) {
                    hasAnyCycle = true;
                    break;
                }
            }
        }

        cout << (hasAnyCycle ? "true" : "false") << " ";
    }

    return 0;
}
