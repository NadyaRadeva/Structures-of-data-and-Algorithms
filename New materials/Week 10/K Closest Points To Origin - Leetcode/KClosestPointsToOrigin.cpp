class Solution {
public:
    struct Comparator {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs) {
            int leftDist = lhs[0] * lhs[0] + lhs[1] * lhs[1];
            int rightDist = rhs[0] * rhs[0] + rhs[1] * rhs[1];

            return leftDist > rightDist;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq(points.begin(), points.end());

        vector<vector<int>> result;

        while (k--) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};
