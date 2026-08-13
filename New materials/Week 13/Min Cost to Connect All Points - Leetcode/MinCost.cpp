class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> used(n, false);

        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int current = -1;

            for (int j = 0; j < n; j++) {
                if (!used[j] && 
                    (current == -1 || minDist[j] < minDist[current])) {
                    current = j;
                }
            }

            used[current] = true;

            totalCost += minDist[current];

            for(int j = 0; j < n; ++j) {
                if(!used[j]) {
                    int distance = abs(points[current][0] - points[j][0]) + abs(points[current][1] - points[j][1]);

                    minDist[j] = min(minDist[j], distance);
                }
            }
        }

        return totalCost;
    }
};
