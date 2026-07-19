#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MIN_NUMBER_OF_PLAYERS = 1;
const int MAX_NUMBER_OF_PLAYERS = 1000000;
const int MIN_NUMBER_OF_TOURNAMENTS = 1;
const int MAX_NUMBER_OF_TOURNAMENTS = 100000;
const int MIN_STUDENT_WEIGHT = 1;
const int MAX_STUDENT_WEIGHT = 1000000000;
const int MIN_TOURNAMENT_WEIGHT = 1;
const int MAX_TOURNAMENT_WEIGHT = 1000000000;

long long findFirst(const vector<long long>& arr, long long minW) {
    if (arr.empty()) {
        return 0;
    }
    
    long long l = 0, r = arr.size() - 1;
    long long idx = arr.size();
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (arr[m] >= minW) {
            idx = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return idx;
}

long long findLast(const vector<long long>& arr, long long maxW) {
    if (arr.empty()) {
        return -1;
    }
    
    long long l = 0, r = arr.size() - 1;
    long long idx = -1;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (arr[m] <= maxW) {
            idx = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return idx;
}

long long countInRange(const vector<long long>& arr, long long minW, long long maxW) {
    long long L = findFirst(arr, minW);
    long long R = findLast(arr, maxW);
    if (R < L) {
        return 0;
    }
    return R - L + 1;
}

int main() {
    long long n, q;
    cin >> n >> q;
    

    vector<long long> playerWeights(n);
    for (long long i = 0; i < n; ++i) {
        cin >> playerWeights[i];
    }

    vector<pair<long long, long long>> tournaments(q);
    for (long long i = 0; i < q; ++i) {
        cin >> tournaments[i].first >> tournaments[i].second;
    }

    sort(playerWeights.begin(), playerWeights.end());

    for (long long i = 0; i < q; ++i) {
        long long count = countInRange(playerWeights, tournaments[i].first, tournaments[i].second);
        cout << count << endl;
    }

    return 0;
}
