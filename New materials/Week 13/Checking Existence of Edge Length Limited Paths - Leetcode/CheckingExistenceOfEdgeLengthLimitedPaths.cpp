class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries) {

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<vector<int>> sortedQueries;

        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({
                queries[i][0],
                queries[i][1],
                queries[i][2],
                i
            });
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<bool> answer(queries.size());

        int edgeIndex = 0;

        for (auto& query : sortedQueries) {

            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int originalIndex = query[3];

            while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit) {

                int a = edgeList[edgeIndex][0];
                int b = edgeList[edgeIndex][1];

                unite(a, b);

                edgeIndex++;
            }

            answer[originalIndex] = (find(u) == find(v));
        }

        return answer;
    }
};
