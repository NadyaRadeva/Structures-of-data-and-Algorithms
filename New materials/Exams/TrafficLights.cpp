// https://www.hackerrank.com/contests/sda-practicum-test-1/challenges/traffic-light-groups/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMake(vector<int>& installed, int m, int k, int day) {
    int groups = 0;
    int consecutive = 0;

    for (int i = 0; i < installed.size(); ++i) {

        if (installed[i] <= day) {
            consecutive++;

            if (consecutive == k) {
                groups++;
                consecutive = 0;
            }
        }
        else {
            consecutive = 0;
        }
    }

    return groups >= m;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> installed(n);

    for (int i = 0; i < n; ++i) {
        cin >> installed[i];
    }

    if (1LL * m * k > n) {
        cout << -1 << endl;
        return 0;
    }

    int left = 1;
    int right = *max_element(installed.begin(), installed.end());

    int answer = -1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (canMake(installed, m, k, mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}
