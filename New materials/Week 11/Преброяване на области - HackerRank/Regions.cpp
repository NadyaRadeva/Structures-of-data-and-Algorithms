#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int current, vector<vector<int>>& graph, vector<bool>& visited) {
    // Mark the current city as visited
    visited[current] = true;

    // Visit all cities connected to current
    for (int neighbor : graph[current]) {
        // If we haven't visited this city yet,
        // continue DFS from it
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countRegions(int n, vector<vector<int>>& graph) {
    // Initially, no city has been visited
    vector<bool> visited(n, false);

    int regions = 0;

    // Try to start DFS from every city
    for (int i = 0; i < n; ++i) {

        // If this city hasn't been visited,
        // it belongs to a new region
        if (!visited[i]) {

            dfs(i, graph, visited);

            // One complete connected component found
            regions++;
        }
    }

    return regions;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        vector<vector<int>> graph(X);

        for (int i = 0; i < Y; ++i) {
            int x, y;
            cin >> x >> y;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        cout << countRegions(X, graph) << " ";
    }

    return 0;
}
