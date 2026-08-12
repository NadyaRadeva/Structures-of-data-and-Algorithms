class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;

        vector<int> dist(n, INF);

        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist;

            for (auto flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (dist[from] == INF) {
                    continue;
                }

                temp[to] = min(
                    temp[to],
                    dist[from] + price
                );
            }

            dist = temp;
        }

        if (dist[dst] == INF) {
            return -1;
        }

        return dist[dst];
    }
};
