class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        vector<double> probability(n, 0.0);

        probability[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});

        while (!pq.empty()) {

            double currentProb = pq.top().first;
            int currentNode = pq.top().second;

            pq.pop();

            if (currentProb < probability[currentNode]) {
                continue;
            }

            if (currentNode == end_node) {
                return currentProb;
            }

            for (auto edge : graph[currentNode]) {

                int neighbor = edge.first;
                double edgeProb = edge.second;

                double newProb = currentProb * edgeProb;

                if (newProb > probability[neighbor]) {

                    probability[neighbor] = newProb;

                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0;
    }
};
