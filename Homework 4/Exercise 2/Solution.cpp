#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int NUMBER_OF_PEOPLE_MIN = 0;
const int NUMBER_OF_PEOPLE_MAX = 1000000;
const int K_MIN = 0;
const long POINTS_MIN = -1000000000;
const int POINTS_MAX = 1000000000;

long long findMinSumPoints(vector<long long>& points, int k) {
    deque<int> dq;
    long long sumMin = 0;

    for (size_t i = 0; i < points.size(); ++i) {
        while (!dq.empty() && dq.front() <= static_cast<int>(i) - k) {
            dq.pop_front();
        }

        while (!dq.empty() && points[dq.back()] >= points[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= static_cast<size_t>(k) - 1) {
            sumMin += points[dq.front()];
        }
    }

    return sumMin;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (n < NUMBER_OF_PEOPLE_MIN || n > NUMBER_OF_PEOPLE_MAX || k < K_MIN || k > n) {
        return 0;
    }

    vector<long long> hardWorkingPoints(n);
    for (int i = 0; i < n; ++i) {
        cin >> hardWorkingPoints[i];
        if(hardWorkingPoints[i] < POINTS_MIN || hardWorkingPoints[i] > POINTS_MAX) {
            return 0;
        }
    }

    cout << findMinSumPoints(hardWorkingPoints, k) << endl;
    return 0;
}
