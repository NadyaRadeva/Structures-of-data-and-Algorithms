class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> answer;

    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = graph[airport].top();
            graph[airport].pop();

            dfs(next);
        }

        answer.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];

            graph[from].push(to);
        }

        dfs("JFK");

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
