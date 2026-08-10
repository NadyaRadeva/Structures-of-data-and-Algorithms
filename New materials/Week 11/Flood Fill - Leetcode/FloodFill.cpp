class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
        // Out of bounds
        if (row < 0 || row >= image.size() ||
            col < 0 || col >= image[0].size()) {
            return;
        }

        // This cell has a different color,
        // so we don't want to fill it.
        if (image[row][col] != oldColor) {
            return;
        }

        // Change the color
        image[row][col] = newColor;

        // Go UP
        dfs(image, row - 1, col, oldColor, newColor);

        // Go DOWN
        dfs(image, row + 1, col, oldColor, newColor);

        // Go LEFT
        dfs(image, row, col - 1, oldColor, newColor);

        // Go RIGHT
        dfs(image, row, col + 1, oldColor, newColor);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Remember the original color
        int oldColor = image[sr][sc];

        // If the colors are already the same,
        // don't do anything.
        //
        // This is also important because otherwise
        // DFS could keep visiting the same cells.
        if (oldColor == color) {
            return image;
        }

        // Start DFS from the given pixel
        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};
