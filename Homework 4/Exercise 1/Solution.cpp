#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MIN_NUMBER_OF_ROWS = 0;
const int MAX_NUMBER_OF_ROWS = 1000;
const int MIN_NUMBER_OF_COLUMNS = 0;
const int MAX_NUMBER_OF_COLUMNS = 1000;
const int MIN_NUMBER_OF_DAYS = 0;
const int MAX_NUMBER_OF_DAYS = 100;
const int NUMBER_OF_DIRECTIONS = 4;

const int ROWS[NUMBER_OF_DIRECTIONS] = { 0, 0 , 1, -1 };
const int COLUMNS[NUMBER_OF_DIRECTIONS] = { 1, -1, 0, 0 };

int findHealthyApplesOneRottenApple(int rows, int columns, int days, int x, int y) {
    queue<pair<int, int>> q;

    int healthyApplesCounter = rows * columns - 1;

    vector<vector<int>> grid(rows, vector<int>(columns, 0));
    int rx = x - 1;
    int ry = y - 1;

    grid[rx][ry] = 1;
    q.push({ rx, ry });

    while (!q.empty() && days > 0) {
        int currentLevelSize = q.size();
        for (int i = 0; i < currentLevelSize; ++i) {
            pair<int, int> currentCell = q.front();
            q.pop();
            for (int direction = 0; direction < NUMBER_OF_DIRECTIONS; ++direction) {
                int newRow = currentCell.first + ROWS[direction];
                int newColumn = currentCell.second + COLUMNS[direction];
                if (newRow >= 0 && newRow < rows &&
                    newColumn >= 0 && newColumn < columns &&
                    grid[newRow][newColumn] == 0) {
                    grid[newRow][newColumn] = 1;
                    q.push({ newRow, newColumn });
                    --healthyApplesCounter;
                }
            }
        }
        --days;
    }

    return healthyApplesCounter;
}

int findHealthyApplesTwoRottenApples(int rows, int columns, int days, int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;

    int healthyApplesCounter = rows * columns - 2;

    vector<vector<int>> grid(rows, vector<int>(columns, 0));
    int r1 = x1 - 1;
    int c1 = y1 - 1;
    int r2 = x2 - 1;
    int c2 = y2 - 1;

    grid[r1][c1] = 1;
    grid[r2][c2] = 1;
    q.push({ r1, c1 });
    q.push({ r2, c2 });

    while (!q.empty() && days > 0) {
        int currentLevelSize = q.size();
        for (int i = 0; i < currentLevelSize; ++i) {
            pair<int, int> currentCell = q.front();
            q.pop();
            for (int direction = 0; direction < NUMBER_OF_DIRECTIONS; ++direction) {
                int newRow = currentCell.first + ROWS[direction];
                int newColumn = currentCell.second + COLUMNS[direction];
                if (newRow >= 0 && newRow < rows &&
                    newColumn >= 0 && newColumn < columns &&
                    grid[newRow][newColumn] == 0) {
                    grid[newRow][newColumn] = 1;
                    q.push({ newRow, newColumn });
                    --healthyApplesCounter;
                }
            }
        }
        --days;
    }

    return healthyApplesCounter;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    if (n < MIN_NUMBER_OF_ROWS || n > MAX_NUMBER_OF_ROWS ||
        m < MIN_NUMBER_OF_COLUMNS || m > MAX_NUMBER_OF_COLUMNS ||
        t < MIN_NUMBER_OF_DAYS || t > MAX_NUMBER_OF_DAYS) {
        return 0;
    }

    vector<int> coords;
    int value;
    while (cin >> value) {
        coords.push_back(value);
    }

    if (coords.size() == 2) {
        int x = coords[0];
        int y = coords[1];

        int healthy = findHealthyApplesOneRottenApple(n, m, t, x, y);
        cout << healthy << endl;
    }
    else if (coords.size() == 4) {
        int x1 = coords[0];
        int y1 = coords[1];
        int x2 = coords[2];
        int y2 = coords[3];

        int healthy = findHealthyApplesTwoRottenApples(n, m, t, x1, y1, x2, y2);
        cout << healthy << endl;
    }

    return 0;
}
