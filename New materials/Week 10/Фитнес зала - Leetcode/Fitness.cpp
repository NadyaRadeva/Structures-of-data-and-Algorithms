#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> intervals;

    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;

        if (start != end) {
            intervals.push_back({start, end});
        }
    }

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = 0;

    for (size_t i = 0; i < intervals.size(); ++i) {

        int start = intervals[i].first;
        int end = intervals[i].second;

        while (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);

        answer = max(answer, (int)pq.size());
    }

    cout << answer << endl;

    return 0;
}
