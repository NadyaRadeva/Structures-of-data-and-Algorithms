class Solution {
public:
    // graph[u] = all vertices connected to u
    unordered_map<int, vector<int>> graph;

    // Stores vertices that we have already visited
    unordered_set<int> visited;

    bool dfs(int current, int destination) {
        // If we reached the destination, a path exists.
        if (current == destination) {
            return true;
        }

        // Mark current vertex as visited
        visited.insert(current);

        // Go through all vertices connected to current
        for (int adjacent : graph[current]) {
            // If we haven't visited this vertex yet
            if (!visited.count(adjacent)) {
                // Recursively search from this vertex
                if (dfs(adjacent, destination)) {
                    return true;
                }
            }
        }

        // We couldn't reach destination from current
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build the graph
        for (auto& edge : edges) {
            // edge[0] = first vertex
            // edge[1] = second vertex
            graph[edge[0]].push_back(edge[1]);

            // Because the graph is undirected,
            // we also need the opposite direction.
            graph[edge[1]].push_back(edge[0]);
        }

        // Start DFS from source
        return dfs(source, destination);
    }
};
