class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int INF = 1e9;

        vector<vector<int>> dist(m, vector<int>(n, INF));

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                int cost = grid[nr][nc];

                if (dist[r][c] + cost < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + cost;

                    if (cost == 0) {
                        dq.push_front({nr, nc});
                    }
                    else {
                        dq.push_back({nr, nc});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
