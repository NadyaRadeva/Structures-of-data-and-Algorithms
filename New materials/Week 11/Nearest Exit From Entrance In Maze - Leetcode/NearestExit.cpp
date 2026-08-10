class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        queue<tuple<int, int, int>> q;

        q.push({entrance[0], entrance[1], 0});

        maze[entrance[0]][entrance[1]] = '+';

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {

            auto [row, col, distance] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];

                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols) {
                    continue;
                }

                if (maze[newRow][newCol] == '+') {
                    continue;
                }

                if (newRow == 0 || newRow == rows - 1 ||
                    newCol == 0 || newCol == cols - 1) {

                    return distance + 1;
                }

                maze[newRow][newCol] = '+';

                q.push({
                    newRow,
                    newCol,
                    distance + 1
                });
            }
        }

        return -1;
    }
};
